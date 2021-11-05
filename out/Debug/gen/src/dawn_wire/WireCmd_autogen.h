
#ifndef DAWNWIRE_WIRECMD_AUTOGEN_H_
#define DAWNWIRE_WIRECMD_AUTOGEN_H_

#include <dawn/webgpu.h>

#include "dawn_wire/BufferConsumer.h"
#include "dawn_wire/ObjectType_autogen.h"
#include "dawn_wire/WireResult.h"

namespace dawn_wire {

    using ObjectId = uint32_t;
    using ObjectGeneration = uint32_t;
    struct ObjectHandle {
      ObjectId id;
      ObjectGeneration generation;

      ObjectHandle();
      ObjectHandle(ObjectId id, ObjectGeneration generation);

      ObjectHandle(const volatile ObjectHandle& rhs);
      ObjectHandle& operator=(const volatile ObjectHandle& rhs);

      // MSVC has a bug where it thinks the volatile copy assignment is a duplicate.
      // Workaround this by forwarding to a different function AssignFrom.
      template <typename T>
      ObjectHandle& operator=(const T& rhs) {
          return AssignFrom(rhs);
      }
      ObjectHandle& AssignFrom(const ObjectHandle& rhs);
      ObjectHandle& AssignFrom(const volatile ObjectHandle& rhs);
    };

    // Interface to allocate more space to deserialize pointed-to data.
    // nullptr is treated as an error.
    class DeserializeAllocator {
        public:
            virtual void* GetSpace(size_t size) = 0;
    };

    // Interface to convert an ID to a server object, if possible.
    // Methods return FatalError if the ID is for a non-existent object and Success otherwise.
    class ObjectIdResolver {
        public:
            virtual WireResult GetFromId(ObjectId id, WGPUBindGroup* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUBindGroup* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUBindGroupLayout* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUBindGroupLayout* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUBuffer* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUBuffer* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUCommandBuffer* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUCommandBuffer* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUCommandEncoder* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUCommandEncoder* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUComputePassEncoder* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUComputePassEncoder* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUComputePipeline* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUComputePipeline* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUDevice* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUDevice* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUExternalTexture* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUExternalTexture* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUInstance* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUInstance* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUPipelineLayout* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUPipelineLayout* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUQuerySet* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUQuerySet* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUQueue* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUQueue* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPURenderBundle* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPURenderBundle* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPURenderBundleEncoder* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPURenderBundleEncoder* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPURenderPassEncoder* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPURenderPassEncoder* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPURenderPipeline* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPURenderPipeline* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUSampler* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUSampler* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUShaderModule* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUShaderModule* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUSurface* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUSurface* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUSwapChain* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUSwapChain* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUTexture* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUTexture* out) const = 0;
            virtual WireResult GetFromId(ObjectId id, WGPUTextureView* out) const = 0;
            virtual WireResult GetOptionalFromId(ObjectId id, WGPUTextureView* out) const = 0;
    };

    // Interface to convert a client object to its ID for the wiring.
    class ObjectIdProvider {
        public:
            virtual WireResult GetId(WGPUBindGroup object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUBindGroup object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUBindGroupLayout object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUBindGroupLayout object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUBuffer object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUBuffer object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUCommandBuffer object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUCommandBuffer object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUCommandEncoder object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUCommandEncoder object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUComputePassEncoder object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUComputePassEncoder object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUComputePipeline object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUComputePipeline object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUDevice object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUDevice object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUExternalTexture object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUExternalTexture object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUInstance object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUInstance object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUPipelineLayout object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUPipelineLayout object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUQuerySet object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUQuerySet object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUQueue object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUQueue object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPURenderBundle object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPURenderBundle object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPURenderBundleEncoder object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPURenderBundleEncoder object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPURenderPassEncoder object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPURenderPassEncoder object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPURenderPipeline object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPURenderPipeline object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUSampler object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUSampler object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUShaderModule object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUShaderModule object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUSurface object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUSurface object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUSwapChain object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUSwapChain object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUTexture object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUTexture object, ObjectId* out) const = 0;
            virtual WireResult GetId(WGPUTextureView object, ObjectId* out) const = 0;
            virtual WireResult GetOptionalId(WGPUTextureView object, ObjectId* out) const = 0;
    };

    enum class WireCmd : uint32_t {
        BufferDestroy,
        BufferMapAsync,
        BufferSetLabel,
        BufferUnmap,
        BufferUpdateMappedData,
        CommandEncoderBeginComputePass,
        CommandEncoderBeginRenderPass,
        CommandEncoderCopyBufferToBuffer,
        CommandEncoderCopyBufferToTexture,
        CommandEncoderCopyTextureToBuffer,
        CommandEncoderCopyTextureToTexture,
        CommandEncoderCopyTextureToTextureInternal,
        CommandEncoderFinish,
        CommandEncoderInjectValidationError,
        CommandEncoderInsertDebugMarker,
        CommandEncoderPopDebugGroup,
        CommandEncoderPushDebugGroup,
        CommandEncoderResolveQuerySet,
        CommandEncoderWriteBuffer,
        CommandEncoderWriteTimestamp,
        ComputePassEncoderDispatch,
        ComputePassEncoderDispatchIndirect,
        ComputePassEncoderEndPass,
        ComputePassEncoderInsertDebugMarker,
        ComputePassEncoderPopDebugGroup,
        ComputePassEncoderPushDebugGroup,
        ComputePassEncoderSetBindGroup,
        ComputePassEncoderSetPipeline,
        ComputePassEncoderWriteTimestamp,
        ComputePipelineGetBindGroupLayout,
        ComputePipelineSetLabel,
        DestroyObject,
        DeviceCreateBindGroup,
        DeviceCreateBindGroupLayout,
        DeviceCreateBuffer,
        DeviceCreateCommandEncoder,
        DeviceCreateComputePipeline,
        DeviceCreateComputePipelineAsync,
        DeviceCreateErrorBuffer,
        DeviceCreateExternalTexture,
        DeviceCreatePipelineLayout,
        DeviceCreateQuerySet,
        DeviceCreateRenderBundleEncoder,
        DeviceCreateRenderPipeline,
        DeviceCreateRenderPipelineAsync,
        DeviceCreateSampler,
        DeviceCreateShaderModule,
        DeviceCreateSwapChain,
        DeviceCreateTexture,
        DeviceGetQueue,
        DeviceInjectError,
        DeviceLoseForTesting,
        DevicePopErrorScope,
        DevicePushErrorScope,
        DeviceTick,
        ExternalTextureDestroy,
        InstanceCreateSurface,
        QuerySetDestroy,
        QueueCopyTextureForBrowser,
        QueueOnSubmittedWorkDone,
        QueueSubmit,
        QueueWriteBufferInternal,
        QueueWriteTextureInternal,
        RenderBundleEncoderDraw,
        RenderBundleEncoderDrawIndexed,
        RenderBundleEncoderDrawIndexedIndirect,
        RenderBundleEncoderDrawIndirect,
        RenderBundleEncoderFinish,
        RenderBundleEncoderInsertDebugMarker,
        RenderBundleEncoderPopDebugGroup,
        RenderBundleEncoderPushDebugGroup,
        RenderBundleEncoderSetBindGroup,
        RenderBundleEncoderSetIndexBuffer,
        RenderBundleEncoderSetPipeline,
        RenderBundleEncoderSetVertexBuffer,
        RenderPassEncoderBeginOcclusionQuery,
        RenderPassEncoderDraw,
        RenderPassEncoderDrawIndexed,
        RenderPassEncoderDrawIndexedIndirect,
        RenderPassEncoderDrawIndirect,
        RenderPassEncoderEndOcclusionQuery,
        RenderPassEncoderEndPass,
        RenderPassEncoderExecuteBundles,
        RenderPassEncoderInsertDebugMarker,
        RenderPassEncoderPopDebugGroup,
        RenderPassEncoderPushDebugGroup,
        RenderPassEncoderSetBindGroup,
        RenderPassEncoderSetBlendConstant,
        RenderPassEncoderSetIndexBuffer,
        RenderPassEncoderSetPipeline,
        RenderPassEncoderSetScissorRect,
        RenderPassEncoderSetStencilReference,
        RenderPassEncoderSetVertexBuffer,
        RenderPassEncoderSetViewport,
        RenderPassEncoderWriteTimestamp,
        RenderPipelineGetBindGroupLayout,
        RenderPipelineSetLabel,
        ShaderModuleGetCompilationInfo,
        ShaderModuleSetLabel,
        SwapChainConfigure,
        SwapChainGetCurrentTextureView,
        SwapChainPresent,
        TextureCreateView,
        TextureDestroy,
        TextureSetLabel,
    };

    enum class ReturnWireCmd : uint32_t {
        BufferMapAsyncCallback,
        DeviceCreateComputePipelineAsyncCallback,
        DeviceCreateRenderPipelineAsyncCallback,
        DeviceLoggingCallback,
        DeviceLostCallback,
        DevicePopErrorScopeCallback,
        DeviceUncapturedErrorCallback,
        QueueWorkDoneCallback,
        ShaderModuleGetCompilationInfoCallback,
    };

    struct CmdHeader {
        uint64_t commandSize;
    };


    struct BufferDestroyCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUBuffer self;
};

    struct BufferMapAsyncCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectId bufferId;
    uint64_t requestSerial;
    WGPUMapModeFlags mode;
    uint64_t offset;
    uint64_t size;
};

    struct BufferSetLabelCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUBuffer self;
    char const * label;
};

    struct BufferUnmapCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUBuffer self;
};

    struct BufferUpdateMappedDataCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectId bufferId;
    uint64_t writeDataUpdateInfoLength;
    uint8_t const * writeDataUpdateInfo;
    uint64_t offset;
    uint64_t size;
};

    struct CommandEncoderBeginComputePassCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUComputePassDescriptor const * descriptor;
    ObjectHandle result;
};

    struct CommandEncoderBeginRenderPassCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPURenderPassDescriptor const * descriptor;
    ObjectHandle result;
};

    struct CommandEncoderCopyBufferToBufferCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUBuffer source;
    uint64_t sourceOffset;
    WGPUBuffer destination;
    uint64_t destinationOffset;
    uint64_t size;
};

    struct CommandEncoderCopyBufferToTextureCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUImageCopyBuffer const * source;
    WGPUImageCopyTexture const * destination;
    WGPUExtent3D const * copySize;
};

    struct CommandEncoderCopyTextureToBufferCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUImageCopyTexture const * source;
    WGPUImageCopyBuffer const * destination;
    WGPUExtent3D const * copySize;
};

    struct CommandEncoderCopyTextureToTextureCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUImageCopyTexture const * source;
    WGPUImageCopyTexture const * destination;
    WGPUExtent3D const * copySize;
};

    struct CommandEncoderCopyTextureToTextureInternalCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUImageCopyTexture const * source;
    WGPUImageCopyTexture const * destination;
    WGPUExtent3D const * copySize;
};

    struct CommandEncoderFinishCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUCommandBufferDescriptor const * descriptor;
    ObjectHandle result;
};

    struct CommandEncoderInjectValidationErrorCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    char const * message;
};

    struct CommandEncoderInsertDebugMarkerCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    char const * markerLabel;
};

    struct CommandEncoderPopDebugGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
};

    struct CommandEncoderPushDebugGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    char const * groupLabel;
};

    struct CommandEncoderResolveQuerySetCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUQuerySet querySet;
    uint32_t firstQuery;
    uint32_t queryCount;
    WGPUBuffer destination;
    uint64_t destinationOffset;
};

    struct CommandEncoderWriteBufferCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUBuffer buffer;
    uint64_t bufferOffset;
    uint8_t const * data;
    uint64_t size;
};

    struct CommandEncoderWriteTimestampCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUCommandEncoder self;
    WGPUQuerySet querySet;
    uint32_t queryIndex;
};

    struct ComputePassEncoderDispatchCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePassEncoder self;
    uint32_t x;
    uint32_t y;
    uint32_t z;
};

    struct ComputePassEncoderDispatchIndirectCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePassEncoder self;
    WGPUBuffer indirectBuffer;
    uint64_t indirectOffset;
};

    struct ComputePassEncoderEndPassCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePassEncoder self;
};

    struct ComputePassEncoderInsertDebugMarkerCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePassEncoder self;
    char const * markerLabel;
};

    struct ComputePassEncoderPopDebugGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePassEncoder self;
};

    struct ComputePassEncoderPushDebugGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePassEncoder self;
    char const * groupLabel;
};

    struct ComputePassEncoderSetBindGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePassEncoder self;
    uint32_t groupIndex;
    WGPUBindGroup group;
    uint32_t dynamicOffsetCount;
    uint32_t const * dynamicOffsets;
};

    struct ComputePassEncoderSetPipelineCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePassEncoder self;
    WGPUComputePipeline pipeline;
};

    struct ComputePassEncoderWriteTimestampCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePassEncoder self;
    WGPUQuerySet querySet;
    uint32_t queryIndex;
};

    struct ComputePipelineGetBindGroupLayoutCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePipeline self;
    uint32_t groupIndex;
    ObjectHandle result;
};

    struct ComputePipelineSetLabelCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUComputePipeline self;
    char const * label;
};

    struct DestroyObjectCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectType objectType;
    ObjectId objectId;
};

    struct DeviceCreateBindGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUBindGroupDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateBindGroupLayoutCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUBindGroupLayoutDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateBufferCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);


    ObjectId deviceId;
    WGPUBufferDescriptor const * descriptor;
    ObjectHandle result;
    uint64_t readHandleCreateInfoLength;
    uint8_t const * readHandleCreateInfo;
    uint64_t writeHandleCreateInfoLength;
    uint8_t const * writeHandleCreateInfo;
};

    struct DeviceCreateCommandEncoderCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUCommandEncoderDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateComputePipelineCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUComputePipelineDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateComputePipelineAsyncCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);


    ObjectId deviceId;
    uint64_t requestSerial;
    ObjectHandle pipelineObjectHandle;
    WGPUComputePipelineDescriptor const * descriptor;
};

    struct DeviceCreateErrorBufferCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    ObjectHandle result;
};

    struct DeviceCreateExternalTextureCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUExternalTextureDescriptor const * externalTextureDescriptor;
    ObjectHandle result;
};

    struct DeviceCreatePipelineLayoutCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUPipelineLayoutDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateQuerySetCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUQuerySetDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateRenderBundleEncoderCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPURenderBundleEncoderDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateRenderPipelineCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPURenderPipelineDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateRenderPipelineAsyncCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);


    ObjectId deviceId;
    uint64_t requestSerial;
    ObjectHandle pipelineObjectHandle;
    WGPURenderPipelineDescriptor const * descriptor;
};

    struct DeviceCreateSamplerCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUSamplerDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateShaderModuleCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUShaderModuleDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateSwapChainCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUSurface surface;
    WGPUSwapChainDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceCreateTextureCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUTextureDescriptor const * descriptor;
    ObjectHandle result;
};

    struct DeviceGetQueueCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    ObjectHandle result;
};

    struct DeviceInjectErrorCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUErrorType type;
    char const * message;
};

    struct DeviceLoseForTestingCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
};

    struct DevicePopErrorScopeCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectId deviceId;
    uint64_t requestSerial;
};

    struct DevicePushErrorScopeCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
    WGPUErrorFilter filter;
};

    struct DeviceTickCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUDevice self;
};

    struct ExternalTextureDestroyCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUExternalTexture self;
};

    struct InstanceCreateSurfaceCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUInstance self;
    WGPUSurfaceDescriptor const * descriptor;
    ObjectHandle result;
};

    struct QuerySetDestroyCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUQuerySet self;
};

    struct QueueCopyTextureForBrowserCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUQueue self;
    WGPUImageCopyTexture const * source;
    WGPUImageCopyTexture const * destination;
    WGPUExtent3D const * copySize;
    WGPUCopyTextureForBrowserOptions const * options;
};

    struct QueueOnSubmittedWorkDoneCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectId queueId;
    uint64_t signalValue;
    uint64_t requestSerial;
};

    struct QueueSubmitCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUQueue self;
    uint32_t commandCount;
    WGPUCommandBuffer const * commands;
};

    struct QueueWriteBufferInternalCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectId queueId;
    ObjectId bufferId;
    uint64_t bufferOffset;
    uint8_t const * data;
    uint64_t size;
};

    struct QueueWriteTextureInternalCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);


    ObjectId queueId;
    WGPUImageCopyTexture const * destination;
    uint8_t const * data;
    uint64_t dataSize;
    WGPUTextureDataLayout const * dataLayout;
    WGPUExtent3D const * writeSize;
};

    struct RenderBundleEncoderDrawCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;
};

    struct RenderBundleEncoderDrawIndexedCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t baseVertex;
    uint32_t firstInstance;
};

    struct RenderBundleEncoderDrawIndexedIndirectCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    WGPUBuffer indirectBuffer;
    uint64_t indirectOffset;
};

    struct RenderBundleEncoderDrawIndirectCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    WGPUBuffer indirectBuffer;
    uint64_t indirectOffset;
};

    struct RenderBundleEncoderFinishCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    WGPURenderBundleDescriptor const * descriptor;
    ObjectHandle result;
};

    struct RenderBundleEncoderInsertDebugMarkerCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    char const * markerLabel;
};

    struct RenderBundleEncoderPopDebugGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
};

    struct RenderBundleEncoderPushDebugGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    char const * groupLabel;
};

    struct RenderBundleEncoderSetBindGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    uint32_t groupIndex;
    WGPUBindGroup group;
    uint32_t dynamicOffsetCount;
    uint32_t const * dynamicOffsets;
};

    struct RenderBundleEncoderSetIndexBufferCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    WGPUBuffer buffer;
    WGPUIndexFormat format;
    uint64_t offset;
    uint64_t size;
};

    struct RenderBundleEncoderSetPipelineCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    WGPURenderPipeline pipeline;
};

    struct RenderBundleEncoderSetVertexBufferCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderBundleEncoder self;
    uint32_t slot;
    WGPUBuffer buffer;
    uint64_t offset;
    uint64_t size;
};

    struct RenderPassEncoderBeginOcclusionQueryCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    uint32_t queryIndex;
};

    struct RenderPassEncoderDrawCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;
};

    struct RenderPassEncoderDrawIndexedCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t baseVertex;
    uint32_t firstInstance;
};

    struct RenderPassEncoderDrawIndexedIndirectCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    WGPUBuffer indirectBuffer;
    uint64_t indirectOffset;
};

    struct RenderPassEncoderDrawIndirectCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    WGPUBuffer indirectBuffer;
    uint64_t indirectOffset;
};

    struct RenderPassEncoderEndOcclusionQueryCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
};

    struct RenderPassEncoderEndPassCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
};

    struct RenderPassEncoderExecuteBundlesCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    uint32_t bundlesCount;
    WGPURenderBundle const * bundles;
};

    struct RenderPassEncoderInsertDebugMarkerCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    char const * markerLabel;
};

    struct RenderPassEncoderPopDebugGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
};

    struct RenderPassEncoderPushDebugGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    char const * groupLabel;
};

    struct RenderPassEncoderSetBindGroupCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    uint32_t groupIndex;
    WGPUBindGroup group;
    uint32_t dynamicOffsetCount;
    uint32_t const * dynamicOffsets;
};

    struct RenderPassEncoderSetBlendConstantCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    WGPUColor const * color;
};

    struct RenderPassEncoderSetIndexBufferCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    WGPUBuffer buffer;
    WGPUIndexFormat format;
    uint64_t offset;
    uint64_t size;
};

    struct RenderPassEncoderSetPipelineCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    WGPURenderPipeline pipeline;
};

    struct RenderPassEncoderSetScissorRectCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    uint32_t x;
    uint32_t y;
    uint32_t width;
    uint32_t height;
};

    struct RenderPassEncoderSetStencilReferenceCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    uint32_t reference;
};

    struct RenderPassEncoderSetVertexBufferCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    uint32_t slot;
    WGPUBuffer buffer;
    uint64_t offset;
    uint64_t size;
};

    struct RenderPassEncoderSetViewportCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    float x;
    float y;
    float width;
    float height;
    float minDepth;
    float maxDepth;
};

    struct RenderPassEncoderWriteTimestampCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPassEncoder self;
    WGPUQuerySet querySet;
    uint32_t queryIndex;
};

    struct RenderPipelineGetBindGroupLayoutCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPipeline self;
    uint32_t groupIndex;
    ObjectHandle result;
};

    struct RenderPipelineSetLabelCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPURenderPipeline self;
    char const * label;
};

    struct ShaderModuleGetCompilationInfoCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectId shaderModuleId;
    uint64_t requestSerial;
};

    struct ShaderModuleSetLabelCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUShaderModule self;
    char const * label;
};

    struct SwapChainConfigureCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUSwapChain self;
    WGPUTextureFormat format;
    WGPUTextureUsageFlags allowedUsage;
    uint32_t width;
    uint32_t height;
};

    struct SwapChainGetCurrentTextureViewCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUSwapChain self;
    ObjectHandle result;
};

    struct SwapChainPresentCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUSwapChain self;
};

    struct TextureCreateViewCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUTexture self;
    WGPUTextureViewDescriptor const * descriptor;
    ObjectHandle result;
};

    struct TextureDestroyCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUTexture self;
};

    struct TextureSetLabelCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer, const ObjectIdProvider& objectIdProvider) const;

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator, const ObjectIdResolver& resolver);

    ObjectId selfId;

    WGPUTexture self;
    char const * label;
};


    struct ReturnBufferMapAsyncCallbackCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectHandle buffer;
    uint64_t requestSerial;
    uint32_t status;
    uint64_t readDataUpdateInfoLength;
    uint8_t const * readDataUpdateInfo;
};

    struct ReturnDeviceCreateComputePipelineAsyncCallbackCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectHandle device;
    uint64_t requestSerial;
    WGPUCreatePipelineAsyncStatus status;
    char const * message;
};

    struct ReturnDeviceCreateRenderPipelineAsyncCallbackCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectHandle device;
    uint64_t requestSerial;
    WGPUCreatePipelineAsyncStatus status;
    char const * message;
};

    struct ReturnDeviceLoggingCallbackCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectHandle device;
    WGPULoggingType type;
    char const * message;
};

    struct ReturnDeviceLostCallbackCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectHandle device;
    WGPUDeviceLostReason reason;
    char const * message;
};

    struct ReturnDevicePopErrorScopeCallbackCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectHandle device;
    uint64_t requestSerial;
    WGPUErrorType type;
    char const * message;
};

    struct ReturnDeviceUncapturedErrorCallbackCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectHandle device;
    WGPUErrorType type;
    char const * message;
};

    struct ReturnQueueWorkDoneCallbackCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectHandle queue;
    uint64_t requestSerial;
    WGPUQueueWorkDoneStatus status;
};

    struct ReturnShaderModuleGetCompilationInfoCallbackCmd {
    size_t GetRequiredSize() const;

    WireResult Serialize(size_t commandSize, SerializeBuffer* serializeBuffer) const;
    // Override which drops the provider if it's not needed.
    WireResult Serialize(size_t commandSize,
                         SerializeBuffer* serializeBuffer,
                         const ObjectIdProvider&) const {
        return Serialize(commandSize, serializeBuffer);
    }

    WireResult Deserialize(DeserializeBuffer* deserializeBuffer, DeserializeAllocator* allocator);


    ObjectHandle shaderModule;
    uint64_t requestSerial;
    WGPUCompilationInfoRequestStatus status;
    WGPUCompilationInfo const * info;
};


}  // namespace dawn_wire

#endif // DAWNWIRE_WIRECMD_AUTOGEN_H_
