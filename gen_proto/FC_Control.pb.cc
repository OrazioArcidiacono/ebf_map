// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: FC_Control.proto
// Protobuf C++ Version: 5.29.3

#include "FC_Control.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace fc {

inline constexpr FCAny::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : msg_{},
        _cached_size_{0},
        _oneof_case_{} {}

template <typename>
PROTOBUF_CONSTEXPR FCAny::FCAny(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct FCAnyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FCAnyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~FCAnyDefaultTypeInternal() {}
  union {
    FCAny _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FCAnyDefaultTypeInternal _FCAny_default_instance_;

inline constexpr FCMessage::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : messages_{},
        apiversionid_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        timestamp_{::int64_t{0}},
        messageid_{0},
        correlationid_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR FCMessage::FCMessage(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct FCMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FCMessageDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~FCMessageDefaultTypeInternal() {}
  union {
    FCMessage _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FCMessageDefaultTypeInternal _FCMessage_default_instance_;
}  // namespace fc
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_FC_5fControl_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_FC_5fControl_2eproto = nullptr;
const ::uint32_t
    TableStruct_FC_5fControl_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::fc::FCMessage, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::fc::FCMessage, _impl_.timestamp_),
        PROTOBUF_FIELD_OFFSET(::fc::FCMessage, _impl_.messageid_),
        PROTOBUF_FIELD_OFFSET(::fc::FCMessage, _impl_.correlationid_),
        PROTOBUF_FIELD_OFFSET(::fc::FCMessage, _impl_.messages_),
        PROTOBUF_FIELD_OFFSET(::fc::FCMessage, _impl_.apiversionid_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::fc::FCAny, _internal_metadata_),
        ~0u,  // no _extensions_
        PROTOBUF_FIELD_OFFSET(::fc::FCAny, _impl_._oneof_case_[0]),
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        ::_pbi::kInvalidFieldOffsetTag,
        ::_pbi::kInvalidFieldOffsetTag,
        PROTOBUF_FIELD_OFFSET(::fc::FCAny, _impl_.msg_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::fc::FCMessage)},
        {13, -1, -1, sizeof(::fc::FCAny)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::fc::_FCMessage_default_instance_._instance,
    &::fc::_FCAny_default_instance_._instance,
};
const char descriptor_table_protodef_FC_5fControl_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\020FC_Control.proto\022\002fc\032\030FC_Service_Messa"
    "ge.proto\032\026FC_Route_Message.proto\"{\n\tFCMe"
    "ssage\022\021\n\ttimestamp\030\001 \001(\003\022\021\n\tmessageId\030\002 "
    "\001(\005\022\025\n\rcorrelationId\030\003 \001(\005\022\033\n\010messages\030\004"
    " \003(\0132\t.fc.FCAny\022\024\n\014apiVersionId\030\005 \001(\014\"j\n"
    "\005FCAny\022.\n\017serviceAnnounce\030\001 \001(\0132\023.fc.Ser"
    "viceAnnounceH\000\022*\n\rrouteAnnounce\030\002 \001(\0132\021."
    "fc.RouteAnnounceH\000B\005\n\003msgb\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_FC_5fControl_2eproto_deps[2] =
    {
        &::descriptor_table_FC_5fRoute_5fMessage_2eproto,
        &::descriptor_table_FC_5fService_5fMessage_2eproto,
};
static ::absl::once_flag descriptor_table_FC_5fControl_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_FC_5fControl_2eproto = {
    false,
    false,
    313,
    descriptor_table_protodef_FC_5fControl_2eproto,
    "FC_Control.proto",
    &descriptor_table_FC_5fControl_2eproto_once,
    descriptor_table_FC_5fControl_2eproto_deps,
    2,
    2,
    schemas,
    file_default_instances,
    TableStruct_FC_5fControl_2eproto::offsets,
    file_level_enum_descriptors_FC_5fControl_2eproto,
    file_level_service_descriptors_FC_5fControl_2eproto,
};
namespace fc {
// ===================================================================

class FCMessage::_Internal {
 public:
};

FCMessage::FCMessage(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:fc.FCMessage)
}
inline PROTOBUF_NDEBUG_INLINE FCMessage::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::fc::FCMessage& from_msg)
      : messages_{visibility, arena, from.messages_},
        apiversionid_(arena, from.apiversionid_),
        _cached_size_{0} {}

FCMessage::FCMessage(
    ::google::protobuf::Arena* arena,
    const FCMessage& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  FCMessage* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, timestamp_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, timestamp_),
           offsetof(Impl_, correlationid_) -
               offsetof(Impl_, timestamp_) +
               sizeof(Impl_::correlationid_));

  // @@protoc_insertion_point(copy_constructor:fc.FCMessage)
}
inline PROTOBUF_NDEBUG_INLINE FCMessage::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : messages_{visibility, arena},
        apiversionid_(arena),
        _cached_size_{0} {}

inline void FCMessage::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, timestamp_),
           0,
           offsetof(Impl_, correlationid_) -
               offsetof(Impl_, timestamp_) +
               sizeof(Impl_::correlationid_));
}
FCMessage::~FCMessage() {
  // @@protoc_insertion_point(destructor:fc.FCMessage)
  SharedDtor(*this);
}
inline void FCMessage::SharedDtor(MessageLite& self) {
  FCMessage& this_ = static_cast<FCMessage&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.apiversionid_.Destroy();
  this_._impl_.~Impl_();
}

inline void* FCMessage::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) FCMessage(arena);
}
constexpr auto FCMessage::InternalNewImpl_() {
  constexpr auto arena_bits = ::google::protobuf::internal::EncodePlacementArenaOffsets({
      PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.messages_) +
          decltype(FCMessage::_impl_.messages_)::
              InternalGetArenaOffset(
                  ::google::protobuf::Message::internal_visibility()),
  });
  if (arena_bits.has_value()) {
    return ::google::protobuf::internal::MessageCreator::CopyInit(
        sizeof(FCMessage), alignof(FCMessage), *arena_bits);
  } else {
    return ::google::protobuf::internal::MessageCreator(&FCMessage::PlacementNew_,
                                 sizeof(FCMessage),
                                 alignof(FCMessage));
  }
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull FCMessage::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_FCMessage_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &FCMessage::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<FCMessage>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &FCMessage::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<FCMessage>(), &FCMessage::ByteSizeLong,
            &FCMessage::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(FCMessage, _impl_._cached_size_),
        false,
    },
    &FCMessage::kDescriptorMethods,
    &descriptor_table_FC_5fControl_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* FCMessage::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 5, 1, 0, 2> FCMessage::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    5, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967264,  // skipmap
    offsetof(decltype(_table_), field_entries),
    5,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::fc::FCMessage>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // int64 timestamp = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(FCMessage, _impl_.timestamp_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.timestamp_)}},
    // int32 messageId = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(FCMessage, _impl_.messageid_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.messageid_)}},
    // int32 correlationId = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(FCMessage, _impl_.correlationid_), 63>(),
     {24, 63, 0, PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.correlationid_)}},
    // repeated .fc.FCAny messages = 4;
    {::_pbi::TcParser::FastMtR1,
     {34, 63, 0, PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.messages_)}},
    // bytes apiVersionId = 5;
    {::_pbi::TcParser::FastBS1,
     {42, 63, 0, PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.apiversionid_)}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // int64 timestamp = 1;
    {PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.timestamp_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
    // int32 messageId = 2;
    {PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.messageid_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // int32 correlationId = 3;
    {PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.correlationid_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // repeated .fc.FCAny messages = 4;
    {PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.messages_), 0, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
    // bytes apiVersionId = 5;
    {PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.apiversionid_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBytes | ::_fl::kRepAString)},
  }}, {{
    {::_pbi::TcParser::GetTable<::fc::FCAny>()},
  }}, {{
  }},
};

PROTOBUF_NOINLINE void FCMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:fc.FCMessage)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.messages_.Clear();
  _impl_.apiversionid_.ClearToEmpty();
  ::memset(&_impl_.timestamp_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.correlationid_) -
      reinterpret_cast<char*>(&_impl_.timestamp_)) + sizeof(_impl_.correlationid_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* FCMessage::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const FCMessage& this_ = static_cast<const FCMessage&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* FCMessage::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const FCMessage& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:fc.FCMessage)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // int64 timestamp = 1;
          if (this_._internal_timestamp() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt64ToArrayWithField<1>(
                    stream, this_._internal_timestamp(), target);
          }

          // int32 messageId = 2;
          if (this_._internal_messageid() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt32ToArrayWithField<2>(
                    stream, this_._internal_messageid(), target);
          }

          // int32 correlationId = 3;
          if (this_._internal_correlationid() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt32ToArrayWithField<3>(
                    stream, this_._internal_correlationid(), target);
          }

          // repeated .fc.FCAny messages = 4;
          for (unsigned i = 0, n = static_cast<unsigned>(
                                   this_._internal_messages_size());
               i < n; i++) {
            const auto& repfield = this_._internal_messages().Get(i);
            target =
                ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
                    4, repfield, repfield.GetCachedSize(),
                    target, stream);
          }

          // bytes apiVersionId = 5;
          if (!this_._internal_apiversionid().empty()) {
            const std::string& _s = this_._internal_apiversionid();
            target = stream->WriteBytesMaybeAliased(5, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:fc.FCMessage)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t FCMessage::ByteSizeLong(const MessageLite& base) {
          const FCMessage& this_ = static_cast<const FCMessage&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t FCMessage::ByteSizeLong() const {
          const FCMessage& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:fc.FCMessage)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // repeated .fc.FCAny messages = 4;
            {
              total_size += 1UL * this_._internal_messages_size();
              for (const auto& msg : this_._internal_messages()) {
                total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
              }
            }
          }
           {
            // bytes apiVersionId = 5;
            if (!this_._internal_apiversionid().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                              this_._internal_apiversionid());
            }
            // int64 timestamp = 1;
            if (this_._internal_timestamp() != 0) {
              total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
                  this_._internal_timestamp());
            }
            // int32 messageId = 2;
            if (this_._internal_messageid() != 0) {
              total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
                  this_._internal_messageid());
            }
            // int32 correlationId = 3;
            if (this_._internal_correlationid() != 0) {
              total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
                  this_._internal_correlationid());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void FCMessage::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<FCMessage*>(&to_msg);
  auto& from = static_cast<const FCMessage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:fc.FCMessage)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_messages()->MergeFrom(
      from._internal_messages());
  if (!from._internal_apiversionid().empty()) {
    _this->_internal_set_apiversionid(from._internal_apiversionid());
  }
  if (from._internal_timestamp() != 0) {
    _this->_impl_.timestamp_ = from._impl_.timestamp_;
  }
  if (from._internal_messageid() != 0) {
    _this->_impl_.messageid_ = from._impl_.messageid_;
  }
  if (from._internal_correlationid() != 0) {
    _this->_impl_.correlationid_ = from._impl_.correlationid_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void FCMessage::CopyFrom(const FCMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fc.FCMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void FCMessage::InternalSwap(FCMessage* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.messages_.InternalSwap(&other->_impl_.messages_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.apiversionid_, &other->_impl_.apiversionid_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.correlationid_)
      + sizeof(FCMessage::_impl_.correlationid_)
      - PROTOBUF_FIELD_OFFSET(FCMessage, _impl_.timestamp_)>(
          reinterpret_cast<char*>(&_impl_.timestamp_),
          reinterpret_cast<char*>(&other->_impl_.timestamp_));
}

::google::protobuf::Metadata FCMessage::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class FCAny::_Internal {
 public:
  static constexpr ::int32_t kOneofCaseOffset =
      PROTOBUF_FIELD_OFFSET(::fc::FCAny, _impl_._oneof_case_);
};

void FCAny::set_allocated_serviceannounce(::fc::ServiceAnnounce* serviceannounce) {
  ::google::protobuf::Arena* message_arena = GetArena();
  clear_msg();
  if (serviceannounce) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(serviceannounce)->GetArena();
    if (message_arena != submessage_arena) {
      serviceannounce = ::google::protobuf::internal::GetOwnedMessage(message_arena, serviceannounce, submessage_arena);
    }
    set_has_serviceannounce();
    _impl_.msg_.serviceannounce_ = serviceannounce;
  }
  // @@protoc_insertion_point(field_set_allocated:fc.FCAny.serviceAnnounce)
}
void FCAny::clear_serviceannounce() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (msg_case() == kServiceAnnounce) {
    if (GetArena() == nullptr) {
      delete _impl_.msg_.serviceannounce_;
    } else if (::google::protobuf::internal::DebugHardenClearOneofMessageOnArena()) {
      ::google::protobuf::internal::MaybePoisonAfterClear(_impl_.msg_.serviceannounce_);
    }
    clear_has_msg();
  }
}
void FCAny::set_allocated_routeannounce(::fc::RouteAnnounce* routeannounce) {
  ::google::protobuf::Arena* message_arena = GetArena();
  clear_msg();
  if (routeannounce) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(routeannounce)->GetArena();
    if (message_arena != submessage_arena) {
      routeannounce = ::google::protobuf::internal::GetOwnedMessage(message_arena, routeannounce, submessage_arena);
    }
    set_has_routeannounce();
    _impl_.msg_.routeannounce_ = routeannounce;
  }
  // @@protoc_insertion_point(field_set_allocated:fc.FCAny.routeAnnounce)
}
void FCAny::clear_routeannounce() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (msg_case() == kRouteAnnounce) {
    if (GetArena() == nullptr) {
      delete _impl_.msg_.routeannounce_;
    } else if (::google::protobuf::internal::DebugHardenClearOneofMessageOnArena()) {
      ::google::protobuf::internal::MaybePoisonAfterClear(_impl_.msg_.routeannounce_);
    }
    clear_has_msg();
  }
}
FCAny::FCAny(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:fc.FCAny)
}
inline PROTOBUF_NDEBUG_INLINE FCAny::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::fc::FCAny& from_msg)
      : msg_{},
        _cached_size_{0},
        _oneof_case_{from._oneof_case_[0]} {}

FCAny::FCAny(
    ::google::protobuf::Arena* arena,
    const FCAny& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  FCAny* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  switch (msg_case()) {
    case MSG_NOT_SET:
      break;
      case kServiceAnnounce:
        _impl_.msg_.serviceannounce_ = ::google::protobuf::Message::CopyConstruct<::fc::ServiceAnnounce>(arena, *from._impl_.msg_.serviceannounce_);
        break;
      case kRouteAnnounce:
        _impl_.msg_.routeannounce_ = ::google::protobuf::Message::CopyConstruct<::fc::RouteAnnounce>(arena, *from._impl_.msg_.routeannounce_);
        break;
  }

  // @@protoc_insertion_point(copy_constructor:fc.FCAny)
}
inline PROTOBUF_NDEBUG_INLINE FCAny::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : msg_{},
        _cached_size_{0},
        _oneof_case_{} {}

inline void FCAny::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
FCAny::~FCAny() {
  // @@protoc_insertion_point(destructor:fc.FCAny)
  SharedDtor(*this);
}
inline void FCAny::SharedDtor(MessageLite& self) {
  FCAny& this_ = static_cast<FCAny&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  if (this_.has_msg()) {
    this_.clear_msg();
  }
  this_._impl_.~Impl_();
}

void FCAny::clear_msg() {
// @@protoc_insertion_point(one_of_clear_start:fc.FCAny)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  switch (msg_case()) {
    case kServiceAnnounce: {
      if (GetArena() == nullptr) {
        delete _impl_.msg_.serviceannounce_;
      } else if (::google::protobuf::internal::DebugHardenClearOneofMessageOnArena()) {
        ::google::protobuf::internal::MaybePoisonAfterClear(_impl_.msg_.serviceannounce_);
      }
      break;
    }
    case kRouteAnnounce: {
      if (GetArena() == nullptr) {
        delete _impl_.msg_.routeannounce_;
      } else if (::google::protobuf::internal::DebugHardenClearOneofMessageOnArena()) {
        ::google::protobuf::internal::MaybePoisonAfterClear(_impl_.msg_.routeannounce_);
      }
      break;
    }
    case MSG_NOT_SET: {
      break;
    }
  }
  _impl_._oneof_case_[0] = MSG_NOT_SET;
}


inline void* FCAny::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) FCAny(arena);
}
constexpr auto FCAny::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::ZeroInit(sizeof(FCAny),
                                            alignof(FCAny));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull FCAny::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_FCAny_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &FCAny::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<FCAny>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &FCAny::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<FCAny>(), &FCAny::ByteSizeLong,
            &FCAny::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(FCAny, _impl_._cached_size_),
        false,
    },
    &FCAny::kDescriptorMethods,
    &descriptor_table_FC_5fControl_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* FCAny::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 2, 2, 0, 2> FCAny::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    2,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::fc::FCAny>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // .fc.ServiceAnnounce serviceAnnounce = 1;
    {PROTOBUF_FIELD_OFFSET(FCAny, _impl_.msg_.serviceannounce_), _Internal::kOneofCaseOffset + 0, 0,
    (0 | ::_fl::kFcOneof | ::_fl::kMessage | ::_fl::kTvTable)},
    // .fc.RouteAnnounce routeAnnounce = 2;
    {PROTOBUF_FIELD_OFFSET(FCAny, _impl_.msg_.routeannounce_), _Internal::kOneofCaseOffset + 0, 1,
    (0 | ::_fl::kFcOneof | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::fc::ServiceAnnounce>()},
    {::_pbi::TcParser::GetTable<::fc::RouteAnnounce>()},
  }}, {{
  }},
};

PROTOBUF_NOINLINE void FCAny::Clear() {
// @@protoc_insertion_point(message_clear_start:fc.FCAny)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clear_msg();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* FCAny::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const FCAny& this_ = static_cast<const FCAny&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* FCAny::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const FCAny& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:fc.FCAny)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          switch (this_.msg_case()) {
            case kServiceAnnounce: {
              target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
                  1, *this_._impl_.msg_.serviceannounce_, this_._impl_.msg_.serviceannounce_->GetCachedSize(), target,
                  stream);
              break;
            }
            case kRouteAnnounce: {
              target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
                  2, *this_._impl_.msg_.routeannounce_, this_._impl_.msg_.routeannounce_->GetCachedSize(), target,
                  stream);
              break;
            }
            default:
              break;
          }
          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:fc.FCAny)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t FCAny::ByteSizeLong(const MessageLite& base) {
          const FCAny& this_ = static_cast<const FCAny&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t FCAny::ByteSizeLong() const {
          const FCAny& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:fc.FCAny)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          switch (this_.msg_case()) {
            // .fc.ServiceAnnounce serviceAnnounce = 1;
            case kServiceAnnounce: {
              total_size += 1 +
                            ::google::protobuf::internal::WireFormatLite::MessageSize(*this_._impl_.msg_.serviceannounce_);
              break;
            }
            // .fc.RouteAnnounce routeAnnounce = 2;
            case kRouteAnnounce: {
              total_size += 1 +
                            ::google::protobuf::internal::WireFormatLite::MessageSize(*this_._impl_.msg_.routeannounce_);
              break;
            }
            case MSG_NOT_SET: {
              break;
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void FCAny::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<FCAny*>(&to_msg);
  auto& from = static_cast<const FCAny&>(from_msg);
  ::google::protobuf::Arena* arena = _this->GetArena();
  // @@protoc_insertion_point(class_specific_merge_from_start:fc.FCAny)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (const uint32_t oneof_from_case = from._impl_._oneof_case_[0]) {
    const uint32_t oneof_to_case = _this->_impl_._oneof_case_[0];
    const bool oneof_needs_init = oneof_to_case != oneof_from_case;
    if (oneof_needs_init) {
      if (oneof_to_case != 0) {
        _this->clear_msg();
      }
      _this->_impl_._oneof_case_[0] = oneof_from_case;
    }

    switch (oneof_from_case) {
      case kServiceAnnounce: {
        if (oneof_needs_init) {
          _this->_impl_.msg_.serviceannounce_ =
              ::google::protobuf::Message::CopyConstruct<::fc::ServiceAnnounce>(arena, *from._impl_.msg_.serviceannounce_);
        } else {
          _this->_impl_.msg_.serviceannounce_->MergeFrom(from._internal_serviceannounce());
        }
        break;
      }
      case kRouteAnnounce: {
        if (oneof_needs_init) {
          _this->_impl_.msg_.routeannounce_ =
              ::google::protobuf::Message::CopyConstruct<::fc::RouteAnnounce>(arena, *from._impl_.msg_.routeannounce_);
        } else {
          _this->_impl_.msg_.routeannounce_->MergeFrom(from._internal_routeannounce());
        }
        break;
      }
      case MSG_NOT_SET:
        break;
    }
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void FCAny::CopyFrom(const FCAny& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fc.FCAny)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void FCAny::InternalSwap(FCAny* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_.msg_, other->_impl_.msg_);
  swap(_impl_._oneof_case_[0], other->_impl_._oneof_case_[0]);
}

::google::protobuf::Metadata FCAny::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace fc
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_FC_5fControl_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
