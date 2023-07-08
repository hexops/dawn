//
// Copyright 2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// State.h: Defines the State class, encapsulating raw GL state

#ifndef LIBANGLE_STATE_H_
#define LIBANGLE_STATE_H_

#include <bitset>
#include <memory>

#include "common/Color.h"
#include "common/angleutils.h"
#include "common/bitset_utils.h"
#include "libANGLE/Debug.h"
#include "libANGLE/GLES1State.h"
#include "libANGLE/Overlay.h"
#include "libANGLE/Program.h"
#include "libANGLE/ProgramExecutable.h"
#include "libANGLE/ProgramPipeline.h"
#include "libANGLE/RefCountObject.h"
#include "libANGLE/Renderbuffer.h"
#include "libANGLE/Sampler.h"
#include "libANGLE/Texture.h"
#include "libANGLE/TransformFeedback.h"
#include "libANGLE/Version.h"
#include "libANGLE/VertexArray.h"
#include "libANGLE/angletypes.h"

namespace egl
{
class ShareGroup;
class ContextMutex;
class SingleContextMutex;
}  // namespace egl

namespace gl
{
class BufferManager;
struct Caps;
class Context;
class FramebufferManager;
class MemoryObjectManager;
class ProgramPipelineManager;
class Query;
class RenderbufferManager;
class SamplerManager;
class SemaphoreManager;
class ShaderProgramManager;
class SyncManager;
class TextureManager;
class VertexArray;

static constexpr Version ES_1_0 = Version(1, 0);
static constexpr Version ES_1_1 = Version(1, 1);
static constexpr Version ES_2_0 = Version(2, 0);
static constexpr Version ES_3_0 = Version(3, 0);
static constexpr Version ES_3_1 = Version(3, 1);
static constexpr Version ES_3_2 = Version(3, 2);

template <typename T>
using BufferBindingMap     = angle::PackedEnumMap<BufferBinding, T>;
using BoundBufferMap       = BufferBindingMap<BindingPointer<Buffer>>;
using TextureBindingVector = std::vector<BindingPointer<Texture>>;
using TextureBindingMap    = angle::PackedEnumMap<TextureType, TextureBindingVector>;
using ActiveQueryMap       = angle::PackedEnumMap<QueryType, BindingPointer<Query>>;

class ActiveTexturesCache final : angle::NonCopyable
{
  public:
    ActiveTexturesCache();
    ~ActiveTexturesCache();

    Texture *operator[](size_t textureIndex) const { return mTextures[textureIndex]; }

    void clear();
    void set(size_t textureIndex, Texture *texture);
    void reset(size_t textureIndex);
    bool empty() const;
    size_t size() const { return mTextures.size(); }

  private:
    ActiveTextureArray<Texture *> mTextures;
};

namespace state
{
enum DirtyBitType
{
    // Note: process draw framebuffer binding first, so that other dirty bits whose effect
    // depend on the current draw framebuffer are not processed while the old framebuffer is
    // still bound.
    DIRTY_BIT_DRAW_FRAMEBUFFER_BINDING,
    DIRTY_BIT_READ_FRAMEBUFFER_BINDING,
    DIRTY_BIT_SCISSOR_TEST_ENABLED,
    DIRTY_BIT_SCISSOR,
    DIRTY_BIT_VIEWPORT,
    DIRTY_BIT_DEPTH_RANGE,
    DIRTY_BIT_BLEND_ENABLED,
    DIRTY_BIT_BLEND_COLOR,
    DIRTY_BIT_BLEND_FUNCS,
    DIRTY_BIT_BLEND_EQUATIONS,
    DIRTY_BIT_COLOR_MASK,
    DIRTY_BIT_SAMPLE_ALPHA_TO_COVERAGE_ENABLED,
    DIRTY_BIT_SAMPLE_COVERAGE_ENABLED,
    DIRTY_BIT_SAMPLE_COVERAGE,
    DIRTY_BIT_SAMPLE_MASK_ENABLED,
    DIRTY_BIT_SAMPLE_MASK,
    DIRTY_BIT_DEPTH_TEST_ENABLED,
    DIRTY_BIT_DEPTH_FUNC,
    DIRTY_BIT_DEPTH_MASK,
    DIRTY_BIT_STENCIL_TEST_ENABLED,
    DIRTY_BIT_STENCIL_FUNCS_FRONT,
    DIRTY_BIT_STENCIL_FUNCS_BACK,
    DIRTY_BIT_STENCIL_OPS_FRONT,
    DIRTY_BIT_STENCIL_OPS_BACK,
    DIRTY_BIT_STENCIL_WRITEMASK_FRONT,
    DIRTY_BIT_STENCIL_WRITEMASK_BACK,
    DIRTY_BIT_CULL_FACE_ENABLED,
    DIRTY_BIT_CULL_FACE,
    DIRTY_BIT_FRONT_FACE,
    DIRTY_BIT_POLYGON_OFFSET_FILL_ENABLED,
    DIRTY_BIT_POLYGON_OFFSET,
    DIRTY_BIT_RASTERIZER_DISCARD_ENABLED,
    DIRTY_BIT_LINE_WIDTH,
    DIRTY_BIT_PRIMITIVE_RESTART_ENABLED,
    DIRTY_BIT_CLEAR_COLOR,
    DIRTY_BIT_CLEAR_DEPTH,
    DIRTY_BIT_CLEAR_STENCIL,
    DIRTY_BIT_UNPACK_STATE,
    DIRTY_BIT_UNPACK_BUFFER_BINDING,
    DIRTY_BIT_PACK_STATE,
    DIRTY_BIT_PACK_BUFFER_BINDING,
    DIRTY_BIT_DITHER_ENABLED,
    DIRTY_BIT_RENDERBUFFER_BINDING,
    DIRTY_BIT_VERTEX_ARRAY_BINDING,
    DIRTY_BIT_DRAW_INDIRECT_BUFFER_BINDING,
    DIRTY_BIT_DISPATCH_INDIRECT_BUFFER_BINDING,
    // Note: Fine-grained dirty bits for each index could be an optimization.
    DIRTY_BIT_PROGRAM_BINDING,  // Must be before DIRTY_BIT_PROGRAM_EXECUTABLE
    DIRTY_BIT_PROGRAM_EXECUTABLE,
    // Note: Fine-grained dirty bits for each texture/sampler could be an optimization.
    DIRTY_BIT_SAMPLER_BINDINGS,
    DIRTY_BIT_TEXTURE_BINDINGS,
    DIRTY_BIT_IMAGE_BINDINGS,
    DIRTY_BIT_TRANSFORM_FEEDBACK_BINDING,
    DIRTY_BIT_UNIFORM_BUFFER_BINDINGS,
    DIRTY_BIT_SHADER_STORAGE_BUFFER_BINDING,
    DIRTY_BIT_ATOMIC_COUNTER_BUFFER_BINDING,
    DIRTY_BIT_MULTISAMPLING,
    DIRTY_BIT_SAMPLE_ALPHA_TO_ONE,
    DIRTY_BIT_COVERAGE_MODULATION,                  // CHROMIUM_framebuffer_mixed_samples
    DIRTY_BIT_FRAMEBUFFER_SRGB_WRITE_CONTROL_MODE,  // GL_EXT_sRGB_write_control
    DIRTY_BIT_CURRENT_VALUES,
    DIRTY_BIT_PROVOKING_VERTEX,
    DIRTY_BIT_SAMPLE_SHADING,
    DIRTY_BIT_PATCH_VERTICES,
    DIRTY_BIT_EXTENDED,  // clip distances, mipmap generation hint, derivative hint,
                         // EXT_clip_control, EXT_depth_clamp

    DIRTY_BIT_INVALID,
    DIRTY_BIT_MAX = DIRTY_BIT_INVALID,
};
static_assert(DIRTY_BIT_MAX <= 64, "State dirty bits must be capped at 64");
using DirtyBits = angle::BitSet<DIRTY_BIT_MAX>;

enum ExtendedDirtyBitType
{
    EXTENDED_DIRTY_BIT_CLIP_CONTROL,                  // EXT_clip_control
    EXTENDED_DIRTY_BIT_CLIP_DISTANCES,                // clip distances
    EXTENDED_DIRTY_BIT_DEPTH_CLAMP_ENABLED,           // EXT_depth_clamp
    EXTENDED_DIRTY_BIT_MIPMAP_GENERATION_HINT,        // mipmap generation hint
    EXTENDED_DIRTY_BIT_POLYGON_MODE,                  // NV_polygon_mode
    EXTENDED_DIRTY_BIT_POLYGON_OFFSET_POINT_ENABLED,  // NV_polygon_mode
    EXTENDED_DIRTY_BIT_POLYGON_OFFSET_LINE_ENABLED,   // NV_polygon_mode
    EXTENDED_DIRTY_BIT_SHADER_DERIVATIVE_HINT,        // shader derivative hint
    EXTENDED_DIRTY_BIT_SHADING_RATE,                  // QCOM_shading_rate
    EXTENDED_DIRTY_BIT_LOGIC_OP_ENABLED,              // ANGLE_logic_op
    EXTENDED_DIRTY_BIT_LOGIC_OP,                      // ANGLE_logic_op

    EXTENDED_DIRTY_BIT_INVALID,
    EXTENDED_DIRTY_BIT_MAX = EXTENDED_DIRTY_BIT_INVALID,
};
static_assert(EXTENDED_DIRTY_BIT_MAX <= 32, "State extended dirty bits must be capped at 32");
using ExtendedDirtyBits = angle::BitSet32<EXTENDED_DIRTY_BIT_MAX>;

// TODO(jmadill): Consider storing dirty objects in a list instead of by binding.
enum DirtyObjectType
{
    DIRTY_OBJECT_ACTIVE_TEXTURES,  // Top-level dirty bit. Also see mDirtyActiveTextures.
    DIRTY_OBJECT_TEXTURES_INIT,
    DIRTY_OBJECT_IMAGES_INIT,
    DIRTY_OBJECT_READ_ATTACHMENTS,
    DIRTY_OBJECT_DRAW_ATTACHMENTS,
    DIRTY_OBJECT_READ_FRAMEBUFFER,
    DIRTY_OBJECT_DRAW_FRAMEBUFFER,
    DIRTY_OBJECT_VERTEX_ARRAY,
    DIRTY_OBJECT_TEXTURES,  // Top-level dirty bit. Also see mDirtyTextures.
    DIRTY_OBJECT_IMAGES,    // Top-level dirty bit. Also see mDirtyImages.
    DIRTY_OBJECT_SAMPLERS,  // Top-level dirty bit. Also see mDirtySamplers.
    DIRTY_OBJECT_PROGRAM,
    DIRTY_OBJECT_PROGRAM_PIPELINE_OBJECT,

    DIRTY_OBJECT_INVALID,
    DIRTY_OBJECT_MAX = DIRTY_OBJECT_INVALID,
};
using DirtyObjects = angle::BitSet<DIRTY_OBJECT_MAX>;

}  // namespace state

// This class represents the portion of the GL context's state that is purely local to the context.
// Manipulating this state does not affect the other contexts in any way, nor do operations in other
// contexts affect this.
//
// Note that "currently bound X" states do not belong here because unbinding most objects could lead
// to object destruction which in turn may trigger a notification to an observer that may affect
// another context.
class LocalState : angle::NonCopyable
{
  public:
    LocalState(const EGLenum clientType,
               const Version &clientVersion,
               EGLint profileMask,
               bool debug,
               bool bindGeneratesResourceCHROMIUM,
               bool clientArraysEnabled,
               bool robustResourceInit,
               bool programBinaryCacheEnabled);
    ~LocalState();

    void initialize(Context *context);
    void initializeForCapture(const Context *context);

    void reset();

    EGLenum getClientType() const { return mClientType; }
    EGLint getProfileMask() const { return mProfileMask; }
    const Version &getClientVersion() const { return mClientVersion; }

    const Caps &getCaps() const { return mCaps; }
    const TextureCapsMap &getTextureCaps() const { return mTextureCaps; }
    const Extensions &getExtensions() const { return mExtensions; }
    const Limitations &getLimitations() const { return mLimitations; }

    Caps *getMutableCaps() { return &mCaps; }
    TextureCapsMap *getMutableTextureCaps() { return &mTextureCaps; }
    Extensions *getMutableExtensions() { return &mExtensions; }
    Limitations *getMutableLimitations() { return &mLimitations; }

    // State chunk getters
    const RasterizerState &getRasterizerState() const { return mRasterizer; }
    const BlendState &getBlendState() const { return mBlendState; }
    const BlendStateExt &getBlendStateExt() const { return mBlendStateExt; }
    const DepthStencilState &getDepthStencilState() const { return mDepthStencil; }

    // Clear values
    void setColorClearValue(float red, float green, float blue, float alpha);
    void setDepthClearValue(float depth);
    void setStencilClearValue(int stencil);

    const ColorF &getColorClearValue() const { return mColorClearValue; }
    float getDepthClearValue() const { return mDepthClearValue; }
    int getStencilClearValue() const { return mStencilClearValue; }

    // Write mask manipulation
    void setColorMask(bool red, bool green, bool blue, bool alpha);
    void setColorMaskIndexed(bool red, bool green, bool blue, bool alpha, GLuint index);
    void setDepthMask(bool mask);

    // Discard toggle & query
    bool isRasterizerDiscardEnabled() const { return mRasterizer.rasterizerDiscard; }
    void setRasterizerDiscard(bool enabled);

    // Primitive restart
    bool isPrimitiveRestartEnabled() const { return mPrimitiveRestart; }
    void setPrimitiveRestart(bool enabled);

    // Face culling state manipulation
    bool isCullFaceEnabled() const { return mRasterizer.cullFace; }
    void setCullFace(bool enabled);
    void setCullMode(CullFaceMode mode);
    void setFrontFace(GLenum front);

    // EXT_depth_clamp
    bool isDepthClampEnabled() const { return mRasterizer.depthClamp; }
    void setDepthClamp(bool enabled);

    // Depth test state manipulation
    bool isDepthTestEnabled() const { return mDepthStencil.depthTest; }
    bool isDepthWriteEnabled() const { return mDepthStencil.depthTest && mDepthStencil.depthMask; }
    void setDepthTest(bool enabled);
    void setDepthFunc(GLenum depthFunc);
    void setDepthRange(float zNear, float zFar);
    float getNearPlane() const { return mNearZ; }
    float getFarPlane() const { return mFarZ; }

    // EXT_clip_control
    void setClipControl(ClipOrigin origin, ClipDepthMode depth);
    ClipOrigin getClipOrigin() const { return mClipOrigin; }
    ClipDepthMode getClipDepthMode() const { return mClipDepthMode; }
    bool isClipDepthModeZeroToOne() const { return mClipDepthMode == ClipDepthMode::ZeroToOne; }

    // Blend state manipulation
    bool isBlendEnabled() const { return mBlendStateExt.getEnabledMask().test(0); }
    bool isBlendEnabledIndexed(GLuint index) const
    {
        ASSERT(static_cast<size_t>(index) < mBlendStateExt.getDrawBufferCount());
        return mBlendStateExt.getEnabledMask().test(index);
    }
    DrawBufferMask getBlendEnabledDrawBufferMask() const { return mBlendStateExt.getEnabledMask(); }
    void setBlend(bool enabled);
    void setBlendIndexed(bool enabled, GLuint index);
    void setBlendFactors(GLenum sourceRGB, GLenum destRGB, GLenum sourceAlpha, GLenum destAlpha);
    void setBlendFactorsIndexed(GLenum sourceRGB,
                                GLenum destRGB,
                                GLenum sourceAlpha,
                                GLenum destAlpha,
                                GLuint index);
    void setBlendColor(float red, float green, float blue, float alpha);
    void setBlendEquation(GLenum rgbEquation, GLenum alphaEquation);
    void setBlendEquationIndexed(GLenum rgbEquation, GLenum alphaEquation, GLuint index);
    const ColorF &getBlendColor() const { return mBlendColor; }

    // Stencil state maniupulation
    bool isStencilTestEnabled() const { return mDepthStencil.stencilTest; }
    bool isStencilWriteEnabled() const
    {
        return mDepthStencil.stencilTest &&
               !(mDepthStencil.isStencilNoOp() && mDepthStencil.isStencilBackNoOp());
    }
    void setStencilTest(bool enabled);
    void setStencilParams(GLenum stencilFunc, GLint stencilRef, GLuint stencilMask);
    void setStencilBackParams(GLenum stencilBackFunc, GLint stencilBackRef, GLuint stencilBackMask);
    void setStencilWritemask(GLuint stencilWritemask);
    void setStencilBackWritemask(GLuint stencilBackWritemask);
    void setStencilOperations(GLenum stencilFail,
                              GLenum stencilPassDepthFail,
                              GLenum stencilPassDepthPass);
    void setStencilBackOperations(GLenum stencilBackFail,
                                  GLenum stencilBackPassDepthFail,
                                  GLenum stencilBackPassDepthPass);
    GLint getStencilRef() const { return mStencilRef; }
    GLint getStencilBackRef() const { return mStencilBackRef; }

    PolygonMode getPolygonMode() const { return mRasterizer.polygonMode; }
    void setPolygonMode(PolygonMode mode);

    // Depth bias/polygon offset state manipulation
    bool isPolygonOffsetPointEnabled() const { return mRasterizer.polygonOffsetPoint; }
    bool isPolygonOffsetLineEnabled() const { return mRasterizer.polygonOffsetLine; }
    bool isPolygonOffsetFillEnabled() const { return mRasterizer.polygonOffsetFill; }
    bool isPolygonOffsetEnabled() const { return mRasterizer.isPolygonOffsetEnabled(); }
    void setPolygonOffsetPoint(bool enabled);
    void setPolygonOffsetLine(bool enabled);
    void setPolygonOffsetFill(bool enabled);
    void setPolygonOffsetParams(GLfloat factor, GLfloat units, GLfloat clamp);

    // Multisample coverage state manipulation
    bool isSampleAlphaToCoverageEnabled() const { return mSampleAlphaToCoverage; }
    void setSampleAlphaToCoverage(bool enabled);
    bool isSampleCoverageEnabled() const { return mSampleCoverage; }
    void setSampleCoverage(bool enabled);
    void setSampleCoverageParams(GLclampf value, bool invert);
    GLclampf getSampleCoverageValue() const { return mSampleCoverageValue; }
    bool getSampleCoverageInvert() const { return mSampleCoverageInvert; }

    // Multisample mask state manipulation.
    bool isSampleMaskEnabled() const { return mSampleMask; }
    void setSampleMaskEnabled(bool enabled);
    void setSampleMaskParams(GLuint maskNumber, GLbitfield mask);
    GLbitfield getSampleMaskWord(GLuint maskNumber) const
    {
        ASSERT(maskNumber < mMaxSampleMaskWords);
        return mSampleMaskValues[maskNumber];
    }
    SampleMaskArray<GLbitfield> getSampleMaskValues() const { return mSampleMaskValues; }
    GLuint getMaxSampleMaskWords() const { return mMaxSampleMaskWords; }

    // Multisampling/alpha to one manipulation.
    void setSampleAlphaToOne(bool enabled);
    bool isSampleAlphaToOneEnabled() const { return mSampleAlphaToOne; }
    void setMultisampling(bool enabled);
    bool isMultisamplingEnabled() const { return mMultiSampling; }

    void setSampleShading(bool enabled);
    bool isSampleShadingEnabled() const { return mIsSampleShadingEnabled; }
    void setMinSampleShading(float value);
    float getMinSampleShading() const { return mMinSampleShading; }

    // Scissor test state toggle & query
    bool isScissorTestEnabled() const { return mScissorTest; }
    void setScissorTest(bool enabled);
    void setScissorParams(GLint x, GLint y, GLsizei width, GLsizei height);
    const Rectangle &getScissor() const { return mScissor; }

    // Dither state toggle & query
    bool isDitherEnabled() const { return mRasterizer.dither; }
    void setDither(bool enabled);

    // GL_CHROMIUM_bind_generates_resource
    bool isBindGeneratesResourceEnabled() const { return mBindGeneratesResource; }

    // GL_ANGLE_client_arrays
    bool areClientArraysEnabled() const { return mClientArraysEnabled; }

    // GL_ANGLE_robust_resource_initialization
    bool isRobustResourceInitEnabled() const { return mRobustResourceInit; }

    // GL_ANGLE_program_cache_control
    bool isProgramBinaryCacheEnabled() const { return mProgramBinaryCacheEnabled; }

    // Viewport state setter/getter
    void setViewportParams(GLint x, GLint y, GLsizei width, GLsizei height);
    const Rectangle &getViewport() const { return mViewport; }

    // QCOM_shading_rate helpers
    void setShadingRate(GLenum rate);
    ShadingRate getShadingRate() const { return mShadingRate; }

    // Pixel pack state manipulation
    void setPackAlignment(GLint alignment);
    GLint getPackAlignment() const { return mPack.alignment; }
    void setPackReverseRowOrder(bool reverseRowOrder);
    bool getPackReverseRowOrder() const { return mPack.reverseRowOrder; }
    void setPackRowLength(GLint rowLength);
    GLint getPackRowLength() const { return mPack.rowLength; }
    void setPackSkipRows(GLint skipRows);
    GLint getPackSkipRows() const { return mPack.skipRows; }
    void setPackSkipPixels(GLint skipPixels);
    GLint getPackSkipPixels() const { return mPack.skipPixels; }
    const PixelPackState &getPackState() const { return mPack; }
    PixelPackState &getPackState() { return mPack; }

    // Pixel unpack state manipulation
    void setUnpackAlignment(GLint alignment);
    GLint getUnpackAlignment() const { return mUnpack.alignment; }
    void setUnpackRowLength(GLint rowLength);
    GLint getUnpackRowLength() const { return mUnpack.rowLength; }
    void setUnpackImageHeight(GLint imageHeight);
    GLint getUnpackImageHeight() const { return mUnpack.imageHeight; }
    void setUnpackSkipImages(GLint skipImages);
    GLint getUnpackSkipImages() const { return mUnpack.skipImages; }
    void setUnpackSkipRows(GLint skipRows);
    GLint getUnpackSkipRows() const { return mUnpack.skipRows; }
    void setUnpackSkipPixels(GLint skipPixels);
    GLint getUnpackSkipPixels() const { return mUnpack.skipPixels; }
    const PixelUnpackState &getUnpackState() const { return mUnpack; }
    PixelUnpackState &getUnpackState() { return mUnpack; }

    // CHROMIUM_framebuffer_mixed_samples coverage modulation
    void setCoverageModulation(GLenum components);
    GLenum getCoverageModulation() const { return mCoverageModulation; }

    // GL_EXT_sRGB_write_control
    void setFramebufferSRGB(bool sRGB);
    bool getFramebufferSRGB() const { return mFramebufferSRGB; }

    // GL_EXT_tessellation_shader
    void setPatchVertices(GLuint value);
    GLuint getPatchVertices() const { return mPatchVertices; }

    // GL_ANGLE_shader_pixel_local_storage
    void setPixelLocalStorageActivePlanes(GLsizei n);
    GLsizei getPixelLocalStorageActivePlanes() const { return mPixelLocalStorageActivePlanes; }

    // Line width state setter
    void setLineWidth(GLfloat width);
    float getLineWidth() const { return mLineWidth; }

    void setActiveSampler(unsigned int active);
    unsigned int getActiveSampler() const { return static_cast<unsigned int>(mActiveSampler); }

    // Hint setters
    void setGenerateMipmapHint(GLenum hint);
    GLenum getGenerateMipmapHint() const { return mGenerateMipmapHint; }
    void setTextureFilteringHint(GLenum hint);
    GLenum getTextureFilteringHint() const { return mTextureFilteringHint; }
    GLenum getFragmentShaderDerivativeHint() const { return mFragmentShaderDerivativeHint; }
    void setFragmentShaderDerivativeHint(GLenum hint);

    ProvokingVertexConvention getProvokingVertex() const { return mProvokingVertex; }
    void setProvokingVertex(ProvokingVertexConvention val)
    {
        mDirtyBits.set(state::DIRTY_BIT_PROVOKING_VERTEX);
        mProvokingVertex = val;
    }

    const VertexAttribCurrentValueData &getVertexAttribCurrentValue(size_t attribNum) const
    {
        ASSERT(attribNum < mVertexAttribCurrentValues.size());
        return mVertexAttribCurrentValues[attribNum];
    }
    const std::vector<VertexAttribCurrentValueData> &getVertexAttribCurrentValues() const
    {
        return mVertexAttribCurrentValues;
    }
    // This actually clears the current value dirty bits.
    // TODO(jmadill): Pass mutable dirty bits into Impl.
    AttributesMask getAndResetDirtyCurrentValues() const;
    ComponentTypeMask getCurrentValuesTypeMask() const { return mCurrentValuesTypeMask; }

    const ClipDistanceEnableBits &getEnabledClipDistances() const { return mClipDistancesEnabled; }
    void setClipDistanceEnable(int idx, bool enable);

    bool noSimultaneousConstantColorAndAlphaBlendFunc() const
    {
        return mNoSimultaneousConstantColorAndAlphaBlendFunc;
    }

    GLfloat getBoundingBoxMinX() const { return mBoundingBoxMinX; }
    GLfloat getBoundingBoxMinY() const { return mBoundingBoxMinY; }
    GLfloat getBoundingBoxMinZ() const { return mBoundingBoxMinZ; }
    GLfloat getBoundingBoxMinW() const { return mBoundingBoxMinW; }
    GLfloat getBoundingBoxMaxX() const { return mBoundingBoxMaxX; }
    GLfloat getBoundingBoxMaxY() const { return mBoundingBoxMaxY; }
    GLfloat getBoundingBoxMaxZ() const { return mBoundingBoxMaxZ; }
    GLfloat getBoundingBoxMaxW() const { return mBoundingBoxMaxW; }
    void setBoundingBox(GLfloat minX,
                        GLfloat minY,
                        GLfloat minZ,
                        GLfloat minW,
                        GLfloat maxX,
                        GLfloat maxY,
                        GLfloat maxZ,
                        GLfloat maxW);

    bool isTextureRectangleEnabled() const { return mTextureRectangleEnabled; }

    DrawBufferMask getBlendFuncConstantAlphaDrawBuffers() const
    {
        return mBlendFuncConstantAlphaDrawBuffers;
    }

    DrawBufferMask getBlendFuncConstantColorDrawBuffers() const
    {
        return mBlendFuncConstantColorDrawBuffers;
    }

    void setLogicOpEnabled(bool enabled);
    bool isLogicOpEnabled() const { return mLogicOpEnabled; }

    void setLogicOp(LogicalOperation opcode);
    LogicalOperation getLogicOp() const { return mLogicOp; }

    // Vertex attrib manipulation
    void setVertexAttribf(GLuint index, const GLfloat values[4]);
    void setVertexAttribu(GLuint index, const GLuint values[4]);
    void setVertexAttribi(GLuint index, const GLint values[4]);

    // Debug state
    const Debug &getDebug() const { return mDebug; }
    Debug &getDebug() { return mDebug; }

    // Generic state toggle & query
    void setEnableFeature(GLenum feature, bool enabled);
    void setEnableFeatureIndexed(GLenum feature, bool enabled, GLuint index);
    bool getEnableFeature(GLenum feature) const;
    bool getEnableFeatureIndexed(GLenum feature, GLuint index) const;

    // State query functions
    void getBooleanv(GLenum pname, GLboolean *params) const;
    void getFloatv(GLenum pname, GLfloat *params) const;
    void getIntegerv(GLenum pname, GLint *params) const;
    void getIntegeri_v(GLenum target, GLuint index, GLint *data) const;
    void getBooleani_v(GLenum target, GLuint index, GLboolean *data) const;

    GLES1State *getMutableGLES1State() { return &mGLES1State; }
    const GLES1State &gles1() const { return mGLES1State; }

    const state::DirtyBits &getDirtyBits() const { return mDirtyBits; }
    void clearDirtyBits() { mDirtyBits.reset(); }
    void clearDirtyBits(const state::DirtyBits &bitset) { mDirtyBits &= ~bitset; }
    void setAllDirtyBits()
    {
        mDirtyBits.set();
        mExtendedDirtyBits.set();
        mDirtyCurrentValues.set();
    }

    const state::ExtendedDirtyBits &getExtendedDirtyBits() const { return mExtendedDirtyBits; }
    void clearExtendedDirtyBits() { mExtendedDirtyBits.reset(); }
    void clearExtendedDirtyBits(const state::ExtendedDirtyBits &bitset)
    {
        mExtendedDirtyBits &= ~bitset;
    }

    const state::DirtyObjects &getDirtyObjects() const { return mDirtyObjects; }
    void clearDirtyObjects() { mDirtyObjects.reset(); }

  private:
    bool hasConstantColor(GLenum sourceRGB, GLenum destRGB) const;
    bool hasConstantAlpha(GLenum sourceRGB, GLenum destRGB) const;

    const EGLenum mClientType;
    const EGLint mProfileMask;
    const Version mClientVersion;

    // Caps to use for validation
    Caps mCaps;
    TextureCapsMap mTextureCaps;
    Extensions mExtensions;
    Limitations mLimitations;

    ColorF mColorClearValue;
    GLfloat mDepthClearValue;
    int mStencilClearValue;

    RasterizerState mRasterizer;
    bool mScissorTest;
    Rectangle mScissor;

    bool mNoUnclampedBlendColor;

    BlendState mBlendState;  // Buffer zero blend state legacy struct
    BlendStateExt mBlendStateExt;
    ColorF mBlendColor;
    bool mSampleAlphaToCoverage;
    bool mSampleCoverage;
    GLfloat mSampleCoverageValue;
    bool mSampleCoverageInvert;
    bool mSampleMask;
    GLuint mMaxSampleMaskWords;
    SampleMaskArray<GLbitfield> mSampleMaskValues;
    bool mIsSampleShadingEnabled;
    float mMinSampleShading;

    DepthStencilState mDepthStencil;
    GLint mStencilRef;
    GLint mStencilBackRef;

    GLfloat mLineWidth;

    GLenum mGenerateMipmapHint;
    GLenum mTextureFilteringHint;
    GLenum mFragmentShaderDerivativeHint;

    Rectangle mViewport;
    float mNearZ;
    float mFarZ;

    ClipOrigin mClipOrigin;
    ClipDepthMode mClipDepthMode;

    // GL_ANGLE_provoking_vertex
    ProvokingVertexConvention mProvokingVertex;

    using VertexAttribVector = std::vector<VertexAttribCurrentValueData>;
    VertexAttribVector mVertexAttribCurrentValues;  // From glVertexAttrib
    ComponentTypeMask mCurrentValuesTypeMask;

    // Texture and sampler bindings
    GLint mActiveSampler;  // Active texture unit selector - GL_TEXTURE0

    PixelUnpackState mUnpack;
    PixelPackState mPack;

    bool mPrimitiveRestart;

    bool mMultiSampling;
    bool mSampleAlphaToOne;

    GLenum mCoverageModulation;

    // GL_EXT_sRGB_write_control
    bool mFramebufferSRGB;

    // GL_ANGLE_webgl_compatibility
    bool mTextureRectangleEnabled;

    // GL_ANGLE_logic_op
    bool mLogicOpEnabled;
    LogicalOperation mLogicOp;

    // GL_APPLE_clip_distance / GL_EXT_clip_cull_distance / GL_ANGLE_clip_cull_distance
    ClipDistanceEnableBits mClipDistancesEnabled;

    // GL_EXT_tessellation_shader
    GLuint mPatchVertices;

    // GL_ANGLE_shader_pixel_local_storage
    GLsizei mPixelLocalStorageActivePlanes;

    // GLES1 emulation: state specific to GLES1
    GLES1State mGLES1State;

    // OES_draw_buffers_indexed
    DrawBufferMask mBlendFuncConstantAlphaDrawBuffers;
    DrawBufferMask mBlendFuncConstantColorDrawBuffers;
    bool mNoSimultaneousConstantColorAndAlphaBlendFunc;
    // Whether the indexed variants of setBlend* have been called.  If so, the call to the
    // non-indexed variants are not no-oped.
    bool mSetBlendIndexedInvoked;
    bool mSetBlendFactorsIndexedInvoked;
    bool mSetBlendEquationsIndexedInvoked;

    // GL_EXT_primitive_bounding_box
    GLfloat mBoundingBoxMinX;
    GLfloat mBoundingBoxMinY;
    GLfloat mBoundingBoxMinZ;
    GLfloat mBoundingBoxMinW;
    GLfloat mBoundingBoxMaxX;
    GLfloat mBoundingBoxMaxY;
    GLfloat mBoundingBoxMaxZ;
    GLfloat mBoundingBoxMaxW;

    // QCOM_shading_rate
    bool mShadingRatePreserveAspectRatio;
    ShadingRate mShadingRate;

    // GL_ARM_shader_framebuffer_fetch
    bool mFetchPerSample;

    const bool mBindGeneratesResource;
    const bool mClientArraysEnabled;
    const bool mRobustResourceInit;
    const bool mProgramBinaryCacheEnabled;

    Debug mDebug;

    state::DirtyBits mDirtyBits;
    state::ExtendedDirtyBits mExtendedDirtyBits;
    state::DirtyObjects mDirtyObjects;
    mutable AttributesMask mDirtyCurrentValues;
};

// This class represents all of the GL context's state.
class State : angle::NonCopyable
{
  public:
    State(const State *shareContextState,
          egl::ShareGroup *shareGroup,
          TextureManager *shareTextures,
          SemaphoreManager *shareSemaphores,
          egl::ContextMutex *sharedContextMutex,
          egl::SingleContextMutex *singleContextMutex,
          const OverlayType *overlay,
          const EGLenum clientType,
          const Version &clientVersion,
          EGLint profileMask,
          bool debug,
          bool bindGeneratesResourceCHROMIUM,
          bool clientArraysEnabled,
          bool robustResourceInit,
          bool programBinaryCacheEnabled,
          EGLenum contextPriority,
          bool hasRobustAccess,
          bool hasProtectedContent);
    ~State();

    void initialize(Context *context);
    void reset(const Context *context);

    // Getters
    ContextID getContextID() const { return mID; }
    EGLenum getClientType() const { return mLocalState.getClientType(); }
    EGLint getProfileMask() const { return mLocalState.getProfileMask(); }
    EGLenum getContextPriority() const { return mContextPriority; }
    bool hasRobustAccess() const { return mHasRobustAccess; }
    bool hasProtectedContent() const { return mHasProtectedContent; }
    bool isDebugContext() const { return mIsDebugContext; }
    GLint getClientMajorVersion() const { return getClientVersion().major; }
    GLint getClientMinorVersion() const { return getClientVersion().minor; }
    const Version &getClientVersion() const { return mLocalState.getClientVersion(); }
    egl::ShareGroup *getShareGroup() const { return mShareGroup; }

    bool isWebGL() const { return getExtensions().webglCompatibilityANGLE; }

    bool isWebGL1() const { return (isWebGL() && getClientVersion().major == 2); }

    bool isGLES1() const { return getClientVersion() < ES_2_0; }

    const Caps &getCaps() const { return mLocalState.getCaps(); }
    const TextureCapsMap &getTextureCaps() const { return mLocalState.getTextureCaps(); }
    const Extensions &getExtensions() const { return mLocalState.getExtensions(); }
    const Limitations &getLimitations() const { return mLocalState.getLimitations(); }

    Caps *getMutableCaps() { return mLocalState.getMutableCaps(); }
    TextureCapsMap *getMutableTextureCaps() { return mLocalState.getMutableTextureCaps(); }
    Extensions *getMutableExtensions() { return mLocalState.getMutableExtensions(); }
    Limitations *getMutableLimitations() { return mLocalState.getMutableLimitations(); }

    const TextureCaps &getTextureCap(GLenum internalFormat) const
    {
        return getTextureCaps().get(internalFormat);
    }

    bool allActiveDrawBufferChannelsMasked() const;
    bool anyActiveDrawBufferChannelMasked() const;

    // Texture binding & active texture unit manipulation
    void setSamplerTexture(const Context *context, TextureType type, Texture *texture);
    Texture *getTargetTexture(TextureType type) const;

    Texture *getSamplerTexture(unsigned int sampler, TextureType type) const
    {
        ASSERT(sampler < mSamplerTextures[type].size());
        return mSamplerTextures[type][sampler].get();
    }

    TextureID getSamplerTextureId(unsigned int sampler, TextureType type) const;
    void detachTexture(Context *context, const TextureMap &zeroTextures, TextureID texture);
    void initializeZeroTextures(const Context *context, const TextureMap &zeroTextures);

    void invalidateTextureBindings(TextureType type);

    // Sampler object binding manipulation
    void setSamplerBinding(const Context *context, GLuint textureUnit, Sampler *sampler);
    SamplerID getSamplerId(GLuint textureUnit) const
    {
        ASSERT(textureUnit < mSamplers.size());
        return mSamplers[textureUnit].id();
    }

    Sampler *getSampler(GLuint textureUnit) const { return mSamplers[textureUnit].get(); }

    const SamplerBindingVector &getSamplers() const { return mSamplers; }

    void detachSampler(const Context *context, SamplerID sampler);

    // Renderbuffer binding manipulation
    void setRenderbufferBinding(const Context *context, Renderbuffer *renderbuffer);
    RenderbufferID getRenderbufferId() const { return mRenderbuffer.id(); }
    Renderbuffer *getCurrentRenderbuffer() const { return mRenderbuffer.get(); }
    void detachRenderbuffer(Context *context, RenderbufferID renderbuffer);

    // Framebuffer binding manipulation
    void setReadFramebufferBinding(Framebuffer *framebuffer);
    void setDrawFramebufferBinding(Framebuffer *framebuffer);
    Framebuffer *getTargetFramebuffer(GLenum target) const;
    Framebuffer *getReadFramebuffer() const { return mReadFramebuffer; }
    Framebuffer *getDrawFramebuffer() const { return mDrawFramebuffer; }
    Framebuffer *getDefaultFramebuffer() const;

    bool removeReadFramebufferBinding(FramebufferID framebuffer);
    bool removeDrawFramebufferBinding(FramebufferID framebuffer);

    // Vertex array object binding manipulation
    void setVertexArrayBinding(const Context *context, VertexArray *vertexArray);
    bool removeVertexArrayBinding(const Context *context, VertexArrayID vertexArray);
    VertexArrayID getVertexArrayId() const;

    VertexArray *getVertexArray() const
    {
        ASSERT(mVertexArray != nullptr);
        return mVertexArray;
    }

    // If both a Program and a ProgramPipeline are bound, the Program will
    // always override the ProgramPipeline.
    ProgramExecutable *getProgramExecutable() const { return mExecutable; }
    ProgramExecutable *getLinkedProgramExecutable(const Context *context) const
    {
        if (mProgram)
        {
            mProgram->resolveLink(context);
        }
        else if (mProgramPipeline.get())
        {
            mProgramPipeline->resolveLink(context);
        }
        return mExecutable;
    }

    // Program binding manipulation
    angle::Result setProgram(const Context *context, Program *newProgram);

    Program *getProgram() const
    {
        ASSERT(!mProgram || !mProgram->isLinking());
        return mProgram;
    }

    Program *getLinkedProgram(const Context *context) const
    {
        if (mProgram)
        {
            mProgram->resolveLink(context);
        }
        return mProgram;
    }

    ProgramPipeline *getProgramPipeline() const { return mProgramPipeline.get(); }

    ProgramPipeline *getLinkedProgramPipeline(const Context *context) const
    {
        if (mProgramPipeline.get())
        {
            mProgramPipeline->resolveLink(context);
        }
        return mProgramPipeline.get();
    }

    // Transform feedback object (not buffer) binding manipulation
    void setTransformFeedbackBinding(const Context *context, TransformFeedback *transformFeedback);
    TransformFeedback *getCurrentTransformFeedback() const { return mTransformFeedback.get(); }

    ANGLE_INLINE bool isTransformFeedbackActive() const
    {
        TransformFeedback *curTransformFeedback = mTransformFeedback.get();
        return curTransformFeedback && curTransformFeedback->isActive();
    }
    ANGLE_INLINE bool isTransformFeedbackActiveUnpaused() const
    {
        TransformFeedback *curTransformFeedback = mTransformFeedback.get();
        return curTransformFeedback && curTransformFeedback->isActive() &&
               !curTransformFeedback->isPaused();
    }

    bool removeTransformFeedbackBinding(const Context *context,
                                        TransformFeedbackID transformFeedback);

    // Query binding manipulation
    bool isQueryActive(QueryType type) const;
    bool isQueryActive(Query *query) const;
    void setActiveQuery(const Context *context, QueryType type, Query *query);
    QueryID getActiveQueryId(QueryType type) const;
    Query *getActiveQuery(QueryType type) const;

    // Program Pipeline binding manipulation
    angle::Result setProgramPipelineBinding(const Context *context, ProgramPipeline *pipeline);
    void detachProgramPipeline(const Context *context, ProgramPipelineID pipeline);

    //// Typed buffer binding point manipulation ////
    ANGLE_INLINE void setBufferBinding(const Context *context, BufferBinding target, Buffer *buffer)
    {
        (this->*(kBufferSetters[target]))(context, buffer);
    }

    ANGLE_INLINE Buffer *getTargetBuffer(BufferBinding target) const
    {
        switch (target)
        {
            case BufferBinding::ElementArray:
                return getVertexArray()->getElementArrayBuffer();
            default:
                return mBoundBuffers[target].get();
        }
    }

    ANGLE_INLINE Buffer *getArrayBuffer() const { return getTargetBuffer(BufferBinding::Array); }

    angle::Result setIndexedBufferBinding(const Context *context,
                                          BufferBinding target,
                                          GLuint index,
                                          Buffer *buffer,
                                          GLintptr offset,
                                          GLsizeiptr size);

    size_t getAtomicCounterBufferCount() const { return mAtomicCounterBuffers.size(); }

    ANGLE_INLINE bool hasValidAtomicCounterBuffer() const
    {
        return mBoundAtomicCounterBuffersMask.any();
    }

    const OffsetBindingPointer<Buffer> &getIndexedUniformBuffer(size_t index) const;
    const OffsetBindingPointer<Buffer> &getIndexedAtomicCounterBuffer(size_t index) const;
    const OffsetBindingPointer<Buffer> &getIndexedShaderStorageBuffer(size_t index) const;

    const angle::BitSet<gl::IMPLEMENTATION_MAX_UNIFORM_BUFFER_BINDINGS> &getUniformBuffersMask()
        const
    {
        return mBoundUniformBuffersMask;
    }
    const angle::BitSet<gl::IMPLEMENTATION_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS> &
    getAtomicCounterBuffersMask() const
    {
        return mBoundAtomicCounterBuffersMask;
    }
    const angle::BitSet<gl::IMPLEMENTATION_MAX_SHADER_STORAGE_BUFFER_BINDINGS> &
    getShaderStorageBuffersMask() const
    {
        return mBoundShaderStorageBuffersMask;
    }

    // Detach a buffer from all bindings
    angle::Result detachBuffer(Context *context, const Buffer *buffer);

    // Vertex attrib manipulation
    void setEnableVertexAttribArray(unsigned int attribNum, bool enabled);

    ANGLE_INLINE void setVertexAttribPointer(const Context *context,
                                             unsigned int attribNum,
                                             Buffer *boundBuffer,
                                             GLint size,
                                             VertexAttribType type,
                                             bool normalized,
                                             GLsizei stride,
                                             const void *pointer)
    {
        mVertexArray->setVertexAttribPointer(context, attribNum, boundBuffer, size, type,
                                             normalized, stride, pointer);
        mDirtyObjects.set(state::DIRTY_OBJECT_VERTEX_ARRAY);
    }

    ANGLE_INLINE void setVertexAttribIPointer(const Context *context,
                                              unsigned int attribNum,
                                              Buffer *boundBuffer,
                                              GLint size,
                                              VertexAttribType type,
                                              GLsizei stride,
                                              const void *pointer)
    {
        mVertexArray->setVertexAttribIPointer(context, attribNum, boundBuffer, size, type, stride,
                                              pointer);
        mDirtyObjects.set(state::DIRTY_OBJECT_VERTEX_ARRAY);
    }

    void setVertexAttribDivisor(const Context *context, GLuint index, GLuint divisor);
    const void *getVertexAttribPointer(unsigned int attribNum) const;

    void bindVertexBuffer(const Context *context,
                          GLuint bindingIndex,
                          Buffer *boundBuffer,
                          GLintptr offset,
                          GLsizei stride);
    void setVertexAttribFormat(GLuint attribIndex,
                               GLint size,
                               VertexAttribType type,
                               bool normalized,
                               bool pureInteger,
                               GLuint relativeOffset);

    void setVertexAttribBinding(const Context *context, GLuint attribIndex, GLuint bindingIndex)
    {
        mVertexArray->setVertexAttribBinding(context, attribIndex, bindingIndex);
        mDirtyObjects.set(state::DIRTY_OBJECT_VERTEX_ARRAY);
    }

    void setVertexBindingDivisor(const Context *context, GLuint bindingIndex, GLuint divisor);

    // State query functions
    void getBooleanv(GLenum pname, GLboolean *params) const;
    void getFloatv(GLenum pname, GLfloat *params) const { mLocalState.getFloatv(pname, params); }
    angle::Result getIntegerv(const Context *context, GLenum pname, GLint *params) const;
    void getPointerv(const Context *context, GLenum pname, void **params) const;
    void getIntegeri_v(const Context *context, GLenum target, GLuint index, GLint *data) const;
    void getInteger64i_v(GLenum target, GLuint index, GLint64 *data) const;
    void getBooleani_v(GLenum target, GLuint index, GLboolean *data) const;

    bool isDrawFramebufferBindingDirty() const
    {
        return mDirtyBits.test(state::DIRTY_BIT_DRAW_FRAMEBUFFER_BINDING);
    }

    // Sets the dirty bit for the program executable.
    angle::Result onProgramExecutableChange(const Context *context, Program *program);
    // Sets the dirty bit for the program pipeline executable.
    angle::Result onProgramPipelineExecutableChange(const Context *context);

    const state::DirtyBits getDirtyBits() const { return mDirtyBits | mLocalState.getDirtyBits(); }
    void clearDirtyBits()
    {
        mDirtyBits.reset();
        mLocalState.clearDirtyBits();
    }
    void clearDirtyBits(const state::DirtyBits &bitset)
    {
        mDirtyBits &= ~bitset;
        mLocalState.clearDirtyBits(bitset);
    }
    void setAllDirtyBits()
    {
        mDirtyBits.set();
        mExtendedDirtyBits.set();
        mLocalState.setAllDirtyBits();
    }

    const state::ExtendedDirtyBits getExtendedDirtyBits() const
    {
        return mExtendedDirtyBits | mLocalState.getExtendedDirtyBits();
    }
    void clearExtendedDirtyBits()
    {
        mExtendedDirtyBits.reset();
        mLocalState.clearExtendedDirtyBits();
    }
    void clearExtendedDirtyBits(const state::ExtendedDirtyBits &bitset)
    {
        mExtendedDirtyBits &= ~bitset;
        mLocalState.clearExtendedDirtyBits(bitset);
    }

    void clearDirtyObjects()
    {
        mDirtyObjects.reset();
        mLocalState.clearDirtyObjects();
    }
    void setAllDirtyObjects() { mDirtyObjects.set(); }
    angle::Result syncDirtyObjects(const Context *context,
                                   const state::DirtyObjects &bitset,
                                   Command command);
    angle::Result syncDirtyObject(const Context *context, GLenum target);
    void setObjectDirty(GLenum target);
    void setTextureDirty(size_t textureUnitIndex);
    void setSamplerDirty(size_t samplerIndex);

    ANGLE_INLINE void setReadFramebufferDirty()
    {
        mDirtyObjects.set(state::DIRTY_OBJECT_READ_FRAMEBUFFER);
        mDirtyObjects.set(state::DIRTY_OBJECT_READ_ATTACHMENTS);
    }

    ANGLE_INLINE void setDrawFramebufferDirty()
    {
        mDirtyObjects.set(state::DIRTY_OBJECT_DRAW_FRAMEBUFFER);
        mDirtyObjects.set(state::DIRTY_OBJECT_DRAW_ATTACHMENTS);
    }

    void setImageUnit(const Context *context,
                      size_t unit,
                      Texture *texture,
                      GLint level,
                      GLboolean layered,
                      GLint layer,
                      GLenum access,
                      GLenum format);

    const ImageUnit &getImageUnit(size_t unit) const { return mImageUnits[unit]; }
    const ActiveTexturesCache &getActiveTexturesCache() const { return mActiveTexturesCache; }

    // "onActiveTextureChange" is called when a texture binding changes.
    void onActiveTextureChange(const Context *context, size_t textureUnit);

    // "onActiveTextureStateChange" is called when the Texture changed but the binding did not.
    void onActiveTextureStateChange(const Context *context, size_t textureUnit);

    void onImageStateChange(const Context *context, size_t unit);

    void onUniformBufferStateChange(size_t uniformBufferIndex);
    void onAtomicCounterBufferStateChange(size_t atomicCounterBufferIndex);
    void onShaderStorageBufferStateChange(size_t shaderStorageBufferIndex);

    bool isCurrentTransformFeedback(const TransformFeedback *tf) const
    {
        return tf == mTransformFeedback.get();
    }
    bool isCurrentVertexArray(const VertexArray *va) const { return va == mVertexArray; }

    // Helpers for setting bound buffers. They should all have the same signature.
    // Not meant to be called externally. Used for local helpers in State.cpp.
    template <BufferBinding Target>
    void setGenericBufferBindingWithBit(const Context *context, Buffer *buffer);

    template <BufferBinding Target>
    void setGenericBufferBinding(const Context *context, Buffer *buffer);

    using BufferBindingSetter = void (State::*)(const Context *, Buffer *);

    ANGLE_INLINE bool validateSamplerFormats() const
    {
        return (!mExecutable || !(mTexturesIncompatibleWithSamplers.intersects(
                                    mExecutable->getActiveSamplersMask())));
    }

    ANGLE_INLINE void setReadFramebufferBindingDirty()
    {
        mDirtyBits.set(state::DIRTY_BIT_READ_FRAMEBUFFER_BINDING);
    }

    ANGLE_INLINE void setDrawFramebufferBindingDirty()
    {
        mDirtyBits.set(state::DIRTY_BIT_DRAW_FRAMEBUFFER_BINDING);
    }

    const OverlayType *getOverlay() const { return mOverlay; }

    // Not for general use.
    const BufferManager &getBufferManagerForCapture() const { return *mBufferManager; }
    const BoundBufferMap &getBoundBuffersForCapture() const { return mBoundBuffers; }
    const TextureManager &getTextureManagerForCapture() const { return *mTextureManager; }
    const TextureBindingMap &getBoundTexturesForCapture() const { return mSamplerTextures; }
    const RenderbufferManager &getRenderbufferManagerForCapture() const
    {
        return *mRenderbufferManager;
    }
    const FramebufferManager &getFramebufferManagerForCapture() const
    {
        return *mFramebufferManager;
    }
    const ShaderProgramManager &getShaderProgramManagerForCapture() const
    {
        return *mShaderProgramManager;
    }
    const SyncManager &getSyncManagerForCapture() const { return *mSyncManager; }
    const SamplerManager &getSamplerManagerForCapture() const { return *mSamplerManager; }
    const ProgramPipelineManager *getProgramPipelineManagerForCapture() const
    {
        return mProgramPipelineManager;
    }
    const SamplerBindingVector &getSamplerBindingsForCapture() const { return mSamplers; }
    const ActiveQueryMap &getActiveQueriesForCapture() const { return mActiveQueries; }
    void initializeForCapture(const Context *context);

    bool hasConstantAlphaBlendFunc() const
    {
        return (getBlendFuncConstantAlphaDrawBuffers() & getBlendStateExt().getEnabledMask()).any();
    }

    bool hasSimultaneousConstantColorAndAlphaBlendFunc() const
    {
        return (getBlendFuncConstantColorDrawBuffers() & getBlendStateExt().getEnabledMask())
                   .any() &&
               hasConstantAlphaBlendFunc();
    }

    const BufferVector &getOffsetBindingPointerUniformBuffers() const { return mUniformBuffers; }

    const BufferVector &getOffsetBindingPointerAtomicCounterBuffers() const
    {
        return mAtomicCounterBuffers;
    }

    const BufferVector &getOffsetBindingPointerShaderStorageBuffers() const
    {
        return mShaderStorageBuffers;
    }

    ActiveTextureMask getTexturesIncompatibleWithSamplers() const
    {
        return mTexturesIncompatibleWithSamplers;
    }

    const std::vector<ImageUnit> &getImageUnits() const { return mImageUnits; }

    bool hasDisplayTextureShareGroup() const { return mDisplayTextureShareGroup; }

    // GL_KHR_parallel_shader_compile
    void setMaxShaderCompilerThreads(GLuint count);
    GLuint getMaxShaderCompilerThreads() const { return mMaxShaderCompilerThreads; }

    // Convenience functions that forward to context-local state.
    const RasterizerState &getRasterizerState() const { return mLocalState.getRasterizerState(); }
    const BlendState &getBlendState() const { return mLocalState.getBlendState(); }
    const BlendStateExt &getBlendStateExt() const { return mLocalState.getBlendStateExt(); }
    const DepthStencilState &getDepthStencilState() const
    {
        return mLocalState.getDepthStencilState();
    }
    const ColorF &getColorClearValue() const { return mLocalState.getColorClearValue(); }
    float getDepthClearValue() const { return mLocalState.getDepthClearValue(); }
    int getStencilClearValue() const { return mLocalState.getStencilClearValue(); }
    bool isRasterizerDiscardEnabled() const { return mLocalState.isRasterizerDiscardEnabled(); }
    bool isPrimitiveRestartEnabled() const { return mLocalState.isPrimitiveRestartEnabled(); }
    bool isCullFaceEnabled() const { return mLocalState.isCullFaceEnabled(); }
    bool isDepthClampEnabled() const { return mLocalState.isDepthClampEnabled(); }
    bool isDepthTestEnabled() const { return mLocalState.isDepthTestEnabled(); }
    bool isDepthWriteEnabled() const { return mLocalState.isDepthWriteEnabled(); }
    float getNearPlane() const { return mLocalState.getNearPlane(); }
    float getFarPlane() const { return mLocalState.getFarPlane(); }
    ClipOrigin getClipOrigin() const { return mLocalState.getClipOrigin(); }
    ClipDepthMode getClipDepthMode() const { return mLocalState.getClipDepthMode(); }
    bool isClipDepthModeZeroToOne() const { return mLocalState.isClipDepthModeZeroToOne(); }
    bool isBlendEnabled() const { return mLocalState.isBlendEnabled(); }
    bool isBlendEnabledIndexed(GLuint index) const
    {
        return mLocalState.isBlendEnabledIndexed(index);
    }
    DrawBufferMask getBlendEnabledDrawBufferMask() const
    {
        return mLocalState.getBlendEnabledDrawBufferMask();
    }
    const ColorF &getBlendColor() const { return mLocalState.getBlendColor(); }
    bool isStencilTestEnabled() const { return mLocalState.isStencilTestEnabled(); }
    bool isStencilWriteEnabled() const { return mLocalState.isStencilWriteEnabled(); }
    GLint getStencilRef() const { return mLocalState.getStencilRef(); }
    GLint getStencilBackRef() const { return mLocalState.getStencilBackRef(); }
    PolygonMode getPolygonMode() const { return mLocalState.getPolygonMode(); }
    bool isPolygonOffsetPointEnabled() const { return mLocalState.isPolygonOffsetPointEnabled(); }
    bool isPolygonOffsetLineEnabled() const { return mLocalState.isPolygonOffsetLineEnabled(); }
    bool isPolygonOffsetFillEnabled() const { return mLocalState.isPolygonOffsetFillEnabled(); }
    bool isPolygonOffsetEnabled() const { return mLocalState.isPolygonOffsetEnabled(); }
    bool isSampleAlphaToCoverageEnabled() const
    {
        return mLocalState.isSampleAlphaToCoverageEnabled();
    }
    bool isSampleCoverageEnabled() const { return mLocalState.isSampleCoverageEnabled(); }
    GLclampf getSampleCoverageValue() const { return mLocalState.getSampleCoverageValue(); }
    bool getSampleCoverageInvert() const { return mLocalState.getSampleCoverageInvert(); }
    bool isSampleMaskEnabled() const { return mLocalState.isSampleMaskEnabled(); }
    GLbitfield getSampleMaskWord(GLuint maskNumber) const
    {
        return mLocalState.getSampleMaskWord(maskNumber);
    }
    SampleMaskArray<GLbitfield> getSampleMaskValues() const
    {
        return mLocalState.getSampleMaskValues();
    }
    GLuint getMaxSampleMaskWords() const { return mLocalState.getMaxSampleMaskWords(); }
    bool isSampleAlphaToOneEnabled() const { return mLocalState.isSampleAlphaToOneEnabled(); }
    bool isMultisamplingEnabled() const { return mLocalState.isMultisamplingEnabled(); }
    bool isSampleShadingEnabled() const { return mLocalState.isSampleShadingEnabled(); }
    float getMinSampleShading() const { return mLocalState.getMinSampleShading(); }
    bool isScissorTestEnabled() const { return mLocalState.isScissorTestEnabled(); }
    const Rectangle &getScissor() const { return mLocalState.getScissor(); }
    bool isDitherEnabled() const { return mLocalState.isDitherEnabled(); }
    bool isBindGeneratesResourceEnabled() const
    {
        return mLocalState.isBindGeneratesResourceEnabled();
    }
    bool areClientArraysEnabled() const { return mLocalState.areClientArraysEnabled(); }
    bool isRobustResourceInitEnabled() const { return mLocalState.isRobustResourceInitEnabled(); }
    bool isProgramBinaryCacheEnabled() const { return mLocalState.isProgramBinaryCacheEnabled(); }
    const Rectangle &getViewport() const { return mLocalState.getViewport(); }
    ShadingRate getShadingRate() const { return mLocalState.getShadingRate(); }
    GLint getPackAlignment() const { return mLocalState.getPackAlignment(); }
    bool getPackReverseRowOrder() const { return mLocalState.getPackReverseRowOrder(); }
    GLint getPackRowLength() const { return mLocalState.getPackRowLength(); }
    GLint getPackSkipRows() const { return mLocalState.getPackSkipRows(); }
    GLint getPackSkipPixels() const { return mLocalState.getPackSkipPixels(); }
    const PixelPackState &getPackState() const { return mLocalState.getPackState(); }
    PixelPackState &getPackState() { return mLocalState.getPackState(); }
    GLint getUnpackAlignment() const { return mLocalState.getUnpackAlignment(); }
    GLint getUnpackRowLength() const { return mLocalState.getUnpackRowLength(); }
    GLint getUnpackImageHeight() const { return mLocalState.getUnpackImageHeight(); }
    GLint getUnpackSkipImages() const { return mLocalState.getUnpackSkipImages(); }
    GLint getUnpackSkipRows() const { return mLocalState.getUnpackSkipRows(); }
    GLint getUnpackSkipPixels() const { return mLocalState.getUnpackSkipPixels(); }
    const PixelUnpackState &getUnpackState() const { return mLocalState.getUnpackState(); }
    PixelUnpackState &getUnpackState() { return mLocalState.getUnpackState(); }
    GLenum getCoverageModulation() const { return mLocalState.getCoverageModulation(); }
    bool getFramebufferSRGB() const { return mLocalState.getFramebufferSRGB(); }
    GLuint getPatchVertices() const { return mLocalState.getPatchVertices(); }
    void setPixelLocalStorageActivePlanes(GLsizei n)
    {
        mLocalState.setPixelLocalStorageActivePlanes(n);
    }
    GLsizei getPixelLocalStorageActivePlanes() const
    {
        return mLocalState.getPixelLocalStorageActivePlanes();
    }
    float getLineWidth() const { return mLocalState.getLineWidth(); }
    unsigned int getActiveSampler() const { return mLocalState.getActiveSampler(); }
    GLenum getGenerateMipmapHint() const { return mLocalState.getGenerateMipmapHint(); }
    GLenum getTextureFilteringHint() const { return mLocalState.getTextureFilteringHint(); }
    GLenum getFragmentShaderDerivativeHint() const
    {
        return mLocalState.getFragmentShaderDerivativeHint();
    }
    ProvokingVertexConvention getProvokingVertex() const
    {
        return mLocalState.getProvokingVertex();
    }
    const VertexAttribCurrentValueData &getVertexAttribCurrentValue(size_t attribNum) const
    {
        return mLocalState.getVertexAttribCurrentValue(attribNum);
    }
    const std::vector<VertexAttribCurrentValueData> &getVertexAttribCurrentValues() const
    {
        return mLocalState.getVertexAttribCurrentValues();
    }
    AttributesMask getAndResetDirtyCurrentValues() const
    {
        return mLocalState.getAndResetDirtyCurrentValues();
    }
    ComponentTypeMask getCurrentValuesTypeMask() const
    {
        return mLocalState.getCurrentValuesTypeMask();
    }
    const ClipDistanceEnableBits &getEnabledClipDistances() const
    {
        return mLocalState.getEnabledClipDistances();
    }
    bool noSimultaneousConstantColorAndAlphaBlendFunc() const
    {
        return mLocalState.noSimultaneousConstantColorAndAlphaBlendFunc();
    }
    GLfloat getBoundingBoxMinX() const { return mLocalState.getBoundingBoxMinX(); }
    GLfloat getBoundingBoxMinY() const { return mLocalState.getBoundingBoxMinY(); }
    GLfloat getBoundingBoxMinZ() const { return mLocalState.getBoundingBoxMinZ(); }
    GLfloat getBoundingBoxMinW() const { return mLocalState.getBoundingBoxMinW(); }
    GLfloat getBoundingBoxMaxX() const { return mLocalState.getBoundingBoxMaxX(); }
    GLfloat getBoundingBoxMaxY() const { return mLocalState.getBoundingBoxMaxY(); }
    GLfloat getBoundingBoxMaxZ() const { return mLocalState.getBoundingBoxMaxZ(); }
    GLfloat getBoundingBoxMaxW() const { return mLocalState.getBoundingBoxMaxW(); }
    bool isTextureRectangleEnabled() const { return mLocalState.isTextureRectangleEnabled(); }
    DrawBufferMask getBlendFuncConstantAlphaDrawBuffers() const
    {
        return mLocalState.getBlendFuncConstantAlphaDrawBuffers();
    }
    DrawBufferMask getBlendFuncConstantColorDrawBuffers() const
    {
        return mLocalState.getBlendFuncConstantColorDrawBuffers();
    }
    bool isLogicOpEnabled() const { return mLocalState.isLogicOpEnabled(); }
    LogicalOperation getLogicOp() const { return mLocalState.getLogicOp(); }
    const Debug &getDebug() const { return mLocalState.getDebug(); }
    Debug &getDebug() { return mLocalState.getDebug(); }
    bool getEnableFeature(GLenum feature) const { return mLocalState.getEnableFeature(feature); }
    bool getEnableFeatureIndexed(GLenum feature, GLuint index) const
    {
        return mLocalState.getEnableFeatureIndexed(feature, index);
    }
    const LocalState &localState() const { return mLocalState; }
    const GLES1State &gles1() const { return mLocalState.gles1(); }

    // Used by the capture/replay tool to create state.
    LocalState *getMutableLocalStateForCapture() { return &mLocalState; }

  private:
    friend class Context;

    // Used only by the entry points to set local state without holding the share group lock.
    LocalState *getMutableLocalState() { return &mLocalState; }
    GLES1State *getMutableGLES1State() { return mLocalState.getMutableGLES1State(); }

    void unsetActiveTextures(const ActiveTextureMask &textureMask);
    void setActiveTextureDirty(size_t textureIndex, Texture *texture);
    void updateTextureBinding(const Context *context, size_t textureIndex, Texture *texture);
    void updateActiveTextureStateOnSync(const Context *context,
                                        size_t textureIndex,
                                        const Sampler *sampler,
                                        Texture *texture);
    Texture *getTextureForActiveSampler(TextureType type, size_t index);

    // Functions to synchronize dirty states
    angle::Result syncActiveTextures(const Context *context, Command command);
    angle::Result syncTexturesInit(const Context *context, Command command);
    angle::Result syncImagesInit(const Context *context, Command command);
    angle::Result syncReadAttachments(const Context *context, Command command);
    angle::Result syncDrawAttachments(const Context *context, Command command);
    angle::Result syncReadFramebuffer(const Context *context, Command command);
    angle::Result syncDrawFramebuffer(const Context *context, Command command);
    angle::Result syncVertexArray(const Context *context, Command command);
    angle::Result syncTextures(const Context *context, Command command);
    angle::Result syncImages(const Context *context, Command command);
    angle::Result syncSamplers(const Context *context, Command command);
    angle::Result syncProgram(const Context *context, Command command);
    angle::Result syncProgramPipelineObject(const Context *context, Command command);

    using DirtyObjectHandler = angle::Result (State::*)(const Context *context, Command command);

    static constexpr DirtyObjectHandler kDirtyObjectHandlers[state::DIRTY_OBJECT_MAX] = {
        &State::syncActiveTextures,
        &State::syncTexturesInit,
        &State::syncImagesInit,
        &State::syncReadAttachments,
        &State::syncDrawAttachments,
        &State::syncReadFramebuffer,
        &State::syncDrawFramebuffer,
        &State::syncVertexArray,
        &State::syncTextures,
        &State::syncImages,
        &State::syncSamplers,
        &State::syncProgram,
        &State::syncProgramPipelineObject};

    // Robust init must happen before Framebuffer init for the Vulkan back-end.
    static_assert(state::DIRTY_OBJECT_ACTIVE_TEXTURES < state::DIRTY_OBJECT_TEXTURES_INIT,
                  "init order");
    static_assert(state::DIRTY_OBJECT_TEXTURES_INIT < state::DIRTY_OBJECT_DRAW_FRAMEBUFFER,
                  "init order");
    static_assert(state::DIRTY_OBJECT_IMAGES_INIT < state::DIRTY_OBJECT_DRAW_FRAMEBUFFER,
                  "init order");
    static_assert(state::DIRTY_OBJECT_DRAW_ATTACHMENTS < state::DIRTY_OBJECT_DRAW_FRAMEBUFFER,
                  "init order");
    static_assert(state::DIRTY_OBJECT_READ_ATTACHMENTS < state::DIRTY_OBJECT_READ_FRAMEBUFFER,
                  "init order");

    static_assert(state::DIRTY_OBJECT_ACTIVE_TEXTURES == 0,
                  "check DIRTY_OBJECT_ACTIVE_TEXTURES index");
    static_assert(state::DIRTY_OBJECT_TEXTURES_INIT == 1, "check DIRTY_OBJECT_TEXTURES_INIT index");
    static_assert(state::DIRTY_OBJECT_IMAGES_INIT == 2, "check DIRTY_OBJECT_IMAGES_INIT index");
    static_assert(state::DIRTY_OBJECT_READ_ATTACHMENTS == 3,
                  "check DIRTY_OBJECT_READ_ATTACHMENTS index");
    static_assert(state::DIRTY_OBJECT_DRAW_ATTACHMENTS == 4,
                  "check DIRTY_OBJECT_DRAW_ATTACHMENTS index");
    static_assert(state::DIRTY_OBJECT_READ_FRAMEBUFFER == 5,
                  "check DIRTY_OBJECT_READ_FRAMEBUFFER index");
    static_assert(state::DIRTY_OBJECT_DRAW_FRAMEBUFFER == 6,
                  "check DIRTY_OBJECT_DRAW_FRAMEBUFFER index");
    static_assert(state::DIRTY_OBJECT_VERTEX_ARRAY == 7, "check DIRTY_OBJECT_VERTEX_ARRAY index");
    static_assert(state::DIRTY_OBJECT_TEXTURES == 8, "check DIRTY_OBJECT_TEXTURES index");
    static_assert(state::DIRTY_OBJECT_IMAGES == 9, "check DIRTY_OBJECT_IMAGES index");
    static_assert(state::DIRTY_OBJECT_SAMPLERS == 10, "check DIRTY_OBJECT_SAMPLERS index");
    static_assert(state::DIRTY_OBJECT_PROGRAM == 11, "check DIRTY_OBJECT_PROGRAM index");
    static_assert(state::DIRTY_OBJECT_PROGRAM_PIPELINE_OBJECT == 12,
                  "check DIRTY_OBJECT_PROGRAM_PIPELINE_OBJECT index");

    // Dispatch table for buffer update functions.
    static const angle::PackedEnumMap<BufferBinding, BufferBindingSetter> kBufferSetters;

    ContextID mID;

    EGLenum mContextPriority;
    bool mHasRobustAccess;
    bool mHasProtectedContent;
    bool mIsDebugContext;

    egl::ShareGroup *mShareGroup;
    egl::ContextMutex *const mSharedContextMutex;
    egl::SingleContextMutex *const mSingleContextMutex;
    std::atomic<egl::ContextMutex *> mContextMutex;  // Simple pointer without reference counting
    bool mIsSharedContextMutexActive;

    // Resource managers.
    BufferManager *mBufferManager;
    ShaderProgramManager *mShaderProgramManager;
    TextureManager *mTextureManager;
    RenderbufferManager *mRenderbufferManager;
    SamplerManager *mSamplerManager;
    SyncManager *mSyncManager;
    FramebufferManager *mFramebufferManager;
    ProgramPipelineManager *mProgramPipelineManager;
    MemoryObjectManager *mMemoryObjectManager;
    SemaphoreManager *mSemaphoreManager;

    Framebuffer *mReadFramebuffer;
    Framebuffer *mDrawFramebuffer;
    BindingPointer<Renderbuffer> mRenderbuffer;
    Program *mProgram;
    BindingPointer<ProgramPipeline> mProgramPipeline;
    ProgramExecutable *mExecutable;

    VertexArray *mVertexArray;

    TextureBindingMap mSamplerTextures;

    // Active Textures Cache
    // ---------------------
    // The active textures cache gives ANGLE components access to a complete array of textures
    // on a draw call. gl::State implements angle::Observer and watches gl::Texture for state
    // changes via the onSubjectStateChange method above. We update the cache before draws.
    // See Observer.h and the design doc linked there for more info on Subject/Observer events.
    //
    // On state change events (re-binding textures, samplers, programs etc) we clear the cache
    // and flag dirty bits. nullptr indicates unbound or incomplete.
    ActiveTexturesCache mActiveTexturesCache;
    std::vector<angle::ObserverBinding> mCompleteTextureBindings;

    ActiveTextureMask mTexturesIncompatibleWithSamplers;

    SamplerBindingVector mSamplers;

    // It would be nice to merge the image and observer binding. Same for textures.
    std::vector<ImageUnit> mImageUnits;

    ActiveQueryMap mActiveQueries;

    // Stores the currently bound buffer for each binding point. It has an entry for the element
    // array buffer but it should not be used. Instead this bind point is owned by the current
    // vertex array object.
    BoundBufferMap mBoundBuffers;

    BufferVector mUniformBuffers;
    BufferVector mAtomicCounterBuffers;
    BufferVector mShaderStorageBuffers;

    angle::BitSet<gl::IMPLEMENTATION_MAX_UNIFORM_BUFFER_BINDINGS> mBoundUniformBuffersMask;
    angle::BitSet<gl::IMPLEMENTATION_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS>
        mBoundAtomicCounterBuffersMask;
    angle::BitSet<gl::IMPLEMENTATION_MAX_SHADER_STORAGE_BUFFER_BINDINGS>
        mBoundShaderStorageBuffersMask;

    BindingPointer<TransformFeedback> mTransformFeedback;

    bool mDisplayTextureShareGroup;

    // GL_KHR_parallel_shader_compile
    GLuint mMaxShaderCompilerThreads;

    // The Overlay object, used by the backend to render the overlay.
    const OverlayType *mOverlay;

    state::DirtyBits mDirtyBits;
    state::ExtendedDirtyBits mExtendedDirtyBits;
    state::DirtyObjects mDirtyObjects;
    ActiveTextureMask mDirtyActiveTextures;
    ActiveTextureMask mDirtyTextures;
    ActiveTextureMask mDirtySamplers;
    ImageUnitMask mDirtyImages;

    LocalState mLocalState;
};

ANGLE_INLINE angle::Result State::syncDirtyObjects(const Context *context,
                                                   const state::DirtyObjects &bitset,
                                                   Command command)
{
    // Accumulate any dirty objects that might have been set due to context-local state changes.
    mDirtyObjects |= mLocalState.getDirtyObjects();
    mLocalState.clearDirtyObjects();

    const state::DirtyObjects &dirtyObjects = mDirtyObjects & bitset;

    for (size_t dirtyObject : dirtyObjects)
    {
        ANGLE_TRY((this->*kDirtyObjectHandlers[dirtyObject])(context, command));
    }

    mDirtyObjects &= ~dirtyObjects;
    return angle::Result::Continue;
}

}  // namespace gl

#endif  // LIBANGLE_STATE_H_