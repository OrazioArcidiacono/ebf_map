// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: FC_Route_Message.proto
// Protobuf C++ Version: 5.29.3

#include "FC_Route_Message.pb.h"

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

inline constexpr RoutePoint::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : latitude_{0},
        longitude_{0},
        timestamp_{::int64_t{0}},
        speed_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR RoutePoint::RoutePoint(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct RoutePointDefaultTypeInternal {
  PROTOBUF_CONSTEXPR RoutePointDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~RoutePointDefaultTypeInternal() {}
  union {
    RoutePoint _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 RoutePointDefaultTypeInternal _RoutePoint_default_instance_;

inline constexpr RouteAnnounce::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : points_{},
        route_id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        type_{static_cast< ::fc::RouteAnnounce_RouteType >(0)},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR RouteAnnounce::RouteAnnounce(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct RouteAnnounceDefaultTypeInternal {
  PROTOBUF_CONSTEXPR RouteAnnounceDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~RouteAnnounceDefaultTypeInternal() {}
  union {
    RouteAnnounce _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 RouteAnnounceDefaultTypeInternal _RouteAnnounce_default_instance_;
}  // namespace fc
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_FC_5fRoute_5fMessage_2eproto[2];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_FC_5fRoute_5fMessage_2eproto = nullptr;
const ::uint32_t
    TableStruct_FC_5fRoute_5fMessage_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::fc::RoutePoint, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::fc::RoutePoint, _impl_.latitude_),
        PROTOBUF_FIELD_OFFSET(::fc::RoutePoint, _impl_.longitude_),
        PROTOBUF_FIELD_OFFSET(::fc::RoutePoint, _impl_.timestamp_),
        PROTOBUF_FIELD_OFFSET(::fc::RoutePoint, _impl_.speed_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::fc::RouteAnnounce, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::fc::RouteAnnounce, _impl_.route_id_),
        PROTOBUF_FIELD_OFFSET(::fc::RouteAnnounce, _impl_.type_),
        PROTOBUF_FIELD_OFFSET(::fc::RouteAnnounce, _impl_.points_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::fc::RoutePoint)},
        {12, -1, -1, sizeof(::fc::RouteAnnounce)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::fc::_RoutePoint_default_instance_._instance,
    &::fc::_RouteAnnounce_default_instance_._instance,
};
const char descriptor_table_protodef_FC_5fRoute_5fMessage_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\026FC_Route_Message.proto\022\002fc\"S\n\nRoutePoi"
    "nt\022\020\n\010latitude\030\001 \001(\001\022\021\n\tlongitude\030\002 \001(\001\022"
    "\021\n\ttimestamp\030\003 \001(\003\022\r\n\005speed\030\004 \001(\001\"\222\001\n\rRo"
    "uteAnnounce\022\020\n\010route_id\030\001 \001(\t\022)\n\004type\030\002 "
    "\001(\0162\033.fc.RouteAnnounce.RouteType\022\036\n\006poin"
    "ts\030\003 \003(\0132\016.fc.RoutePoint\"$\n\tRouteType\022\t\n"
    "\005ROUTE\020\000\022\014\n\010POSITION\020\001*$\n\tRouteType\022\t\n\005R"
    "OUTE\020\000\022\014\n\010POSITION\020\001b\006proto3"
};
static ::absl::once_flag descriptor_table_FC_5fRoute_5fMessage_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_FC_5fRoute_5fMessage_2eproto = {
    false,
    false,
    308,
    descriptor_table_protodef_FC_5fRoute_5fMessage_2eproto,
    "FC_Route_Message.proto",
    &descriptor_table_FC_5fRoute_5fMessage_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_FC_5fRoute_5fMessage_2eproto::offsets,
    file_level_enum_descriptors_FC_5fRoute_5fMessage_2eproto,
    file_level_service_descriptors_FC_5fRoute_5fMessage_2eproto,
};
namespace fc {
const ::google::protobuf::EnumDescriptor* RouteAnnounce_RouteType_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_FC_5fRoute_5fMessage_2eproto);
  return file_level_enum_descriptors_FC_5fRoute_5fMessage_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t RouteAnnounce_RouteType_internal_data_[] = {
    131072u, 0u, };
bool RouteAnnounce_RouteType_IsValid(int value) {
  return 0 <= value && value <= 1;
}
#if (__cplusplus < 201703) && \
  (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

constexpr RouteAnnounce_RouteType RouteAnnounce::ROUTE;
constexpr RouteAnnounce_RouteType RouteAnnounce::POSITION;
constexpr RouteAnnounce_RouteType RouteAnnounce::RouteType_MIN;
constexpr RouteAnnounce_RouteType RouteAnnounce::RouteType_MAX;
constexpr int RouteAnnounce::RouteType_ARRAYSIZE;

#endif  // (__cplusplus < 201703) &&
        // (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
const ::google::protobuf::EnumDescriptor* RouteType_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_FC_5fRoute_5fMessage_2eproto);
  return file_level_enum_descriptors_FC_5fRoute_5fMessage_2eproto[1];
}
PROTOBUF_CONSTINIT const uint32_t RouteType_internal_data_[] = {
    131072u, 0u, };
bool RouteType_IsValid(int value) {
  return 0 <= value && value <= 1;
}
// ===================================================================

class RoutePoint::_Internal {
 public:
};

RoutePoint::RoutePoint(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:fc.RoutePoint)
}
RoutePoint::RoutePoint(
    ::google::protobuf::Arena* arena, const RoutePoint& from)
    : RoutePoint(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE RoutePoint::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void RoutePoint::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, latitude_),
           0,
           offsetof(Impl_, speed_) -
               offsetof(Impl_, latitude_) +
               sizeof(Impl_::speed_));
}
RoutePoint::~RoutePoint() {
  // @@protoc_insertion_point(destructor:fc.RoutePoint)
  SharedDtor(*this);
}
inline void RoutePoint::SharedDtor(MessageLite& self) {
  RoutePoint& this_ = static_cast<RoutePoint&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.~Impl_();
}

inline void* RoutePoint::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) RoutePoint(arena);
}
constexpr auto RoutePoint::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::ZeroInit(sizeof(RoutePoint),
                                            alignof(RoutePoint));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull RoutePoint::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_RoutePoint_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &RoutePoint::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<RoutePoint>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &RoutePoint::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<RoutePoint>(), &RoutePoint::ByteSizeLong,
            &RoutePoint::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_._cached_size_),
        false,
    },
    &RoutePoint::kDescriptorMethods,
    &descriptor_table_FC_5fRoute_5fMessage_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* RoutePoint::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 4, 0, 0, 2> RoutePoint::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    4, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967280,  // skipmap
    offsetof(decltype(_table_), field_entries),
    4,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::fc::RoutePoint>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // double speed = 4;
    {::_pbi::TcParser::FastF64S1,
     {33, 63, 0, PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.speed_)}},
    // double latitude = 1;
    {::_pbi::TcParser::FastF64S1,
     {9, 63, 0, PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.latitude_)}},
    // double longitude = 2;
    {::_pbi::TcParser::FastF64S1,
     {17, 63, 0, PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.longitude_)}},
    // int64 timestamp = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(RoutePoint, _impl_.timestamp_), 63>(),
     {24, 63, 0, PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.timestamp_)}},
  }}, {{
    65535, 65535
  }}, {{
    // double latitude = 1;
    {PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.latitude_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
    // double longitude = 2;
    {PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.longitude_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
    // int64 timestamp = 3;
    {PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.timestamp_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
    // double speed = 4;
    {PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.speed_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void RoutePoint::Clear() {
// @@protoc_insertion_point(message_clear_start:fc.RoutePoint)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.latitude_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.speed_) -
      reinterpret_cast<char*>(&_impl_.latitude_)) + sizeof(_impl_.speed_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* RoutePoint::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const RoutePoint& this_ = static_cast<const RoutePoint&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* RoutePoint::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const RoutePoint& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:fc.RoutePoint)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // double latitude = 1;
          if (::absl::bit_cast<::uint64_t>(this_._internal_latitude()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteDoubleToArray(
                1, this_._internal_latitude(), target);
          }

          // double longitude = 2;
          if (::absl::bit_cast<::uint64_t>(this_._internal_longitude()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteDoubleToArray(
                2, this_._internal_longitude(), target);
          }

          // int64 timestamp = 3;
          if (this_._internal_timestamp() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt64ToArrayWithField<3>(
                    stream, this_._internal_timestamp(), target);
          }

          // double speed = 4;
          if (::absl::bit_cast<::uint64_t>(this_._internal_speed()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteDoubleToArray(
                4, this_._internal_speed(), target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:fc.RoutePoint)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t RoutePoint::ByteSizeLong(const MessageLite& base) {
          const RoutePoint& this_ = static_cast<const RoutePoint&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t RoutePoint::ByteSizeLong() const {
          const RoutePoint& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:fc.RoutePoint)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // double latitude = 1;
            if (::absl::bit_cast<::uint64_t>(this_._internal_latitude()) != 0) {
              total_size += 9;
            }
            // double longitude = 2;
            if (::absl::bit_cast<::uint64_t>(this_._internal_longitude()) != 0) {
              total_size += 9;
            }
            // int64 timestamp = 3;
            if (this_._internal_timestamp() != 0) {
              total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
                  this_._internal_timestamp());
            }
            // double speed = 4;
            if (::absl::bit_cast<::uint64_t>(this_._internal_speed()) != 0) {
              total_size += 9;
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void RoutePoint::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<RoutePoint*>(&to_msg);
  auto& from = static_cast<const RoutePoint&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:fc.RoutePoint)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (::absl::bit_cast<::uint64_t>(from._internal_latitude()) != 0) {
    _this->_impl_.latitude_ = from._impl_.latitude_;
  }
  if (::absl::bit_cast<::uint64_t>(from._internal_longitude()) != 0) {
    _this->_impl_.longitude_ = from._impl_.longitude_;
  }
  if (from._internal_timestamp() != 0) {
    _this->_impl_.timestamp_ = from._impl_.timestamp_;
  }
  if (::absl::bit_cast<::uint64_t>(from._internal_speed()) != 0) {
    _this->_impl_.speed_ = from._impl_.speed_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void RoutePoint::CopyFrom(const RoutePoint& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fc.RoutePoint)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void RoutePoint::InternalSwap(RoutePoint* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.speed_)
      + sizeof(RoutePoint::_impl_.speed_)
      - PROTOBUF_FIELD_OFFSET(RoutePoint, _impl_.latitude_)>(
          reinterpret_cast<char*>(&_impl_.latitude_),
          reinterpret_cast<char*>(&other->_impl_.latitude_));
}

::google::protobuf::Metadata RoutePoint::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class RouteAnnounce::_Internal {
 public:
};

RouteAnnounce::RouteAnnounce(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:fc.RouteAnnounce)
}
inline PROTOBUF_NDEBUG_INLINE RouteAnnounce::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::fc::RouteAnnounce& from_msg)
      : points_{visibility, arena, from.points_},
        route_id_(arena, from.route_id_),
        _cached_size_{0} {}

RouteAnnounce::RouteAnnounce(
    ::google::protobuf::Arena* arena,
    const RouteAnnounce& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  RouteAnnounce* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  _impl_.type_ = from._impl_.type_;

  // @@protoc_insertion_point(copy_constructor:fc.RouteAnnounce)
}
inline PROTOBUF_NDEBUG_INLINE RouteAnnounce::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : points_{visibility, arena},
        route_id_(arena),
        _cached_size_{0} {}

inline void RouteAnnounce::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.type_ = {};
}
RouteAnnounce::~RouteAnnounce() {
  // @@protoc_insertion_point(destructor:fc.RouteAnnounce)
  SharedDtor(*this);
}
inline void RouteAnnounce::SharedDtor(MessageLite& self) {
  RouteAnnounce& this_ = static_cast<RouteAnnounce&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.route_id_.Destroy();
  this_._impl_.~Impl_();
}

inline void* RouteAnnounce::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) RouteAnnounce(arena);
}
constexpr auto RouteAnnounce::InternalNewImpl_() {
  constexpr auto arena_bits = ::google::protobuf::internal::EncodePlacementArenaOffsets({
      PROTOBUF_FIELD_OFFSET(RouteAnnounce, _impl_.points_) +
          decltype(RouteAnnounce::_impl_.points_)::
              InternalGetArenaOffset(
                  ::google::protobuf::Message::internal_visibility()),
  });
  if (arena_bits.has_value()) {
    return ::google::protobuf::internal::MessageCreator::CopyInit(
        sizeof(RouteAnnounce), alignof(RouteAnnounce), *arena_bits);
  } else {
    return ::google::protobuf::internal::MessageCreator(&RouteAnnounce::PlacementNew_,
                                 sizeof(RouteAnnounce),
                                 alignof(RouteAnnounce));
  }
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull RouteAnnounce::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_RouteAnnounce_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &RouteAnnounce::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<RouteAnnounce>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &RouteAnnounce::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<RouteAnnounce>(), &RouteAnnounce::ByteSizeLong,
            &RouteAnnounce::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(RouteAnnounce, _impl_._cached_size_),
        false,
    },
    &RouteAnnounce::kDescriptorMethods,
    &descriptor_table_FC_5fRoute_5fMessage_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* RouteAnnounce::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 3, 1, 33, 2> RouteAnnounce::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    3, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967288,  // skipmap
    offsetof(decltype(_table_), field_entries),
    3,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::fc::RouteAnnounce>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // string route_id = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(RouteAnnounce, _impl_.route_id_)}},
    // .fc.RouteAnnounce.RouteType type = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(RouteAnnounce, _impl_.type_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(RouteAnnounce, _impl_.type_)}},
    // repeated .fc.RoutePoint points = 3;
    {::_pbi::TcParser::FastMtR1,
     {26, 63, 0, PROTOBUF_FIELD_OFFSET(RouteAnnounce, _impl_.points_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string route_id = 1;
    {PROTOBUF_FIELD_OFFSET(RouteAnnounce, _impl_.route_id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // .fc.RouteAnnounce.RouteType type = 2;
    {PROTOBUF_FIELD_OFFSET(RouteAnnounce, _impl_.type_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kOpenEnum)},
    // repeated .fc.RoutePoint points = 3;
    {PROTOBUF_FIELD_OFFSET(RouteAnnounce, _impl_.points_), 0, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::fc::RoutePoint>()},
  }}, {{
    "\20\10\0\0\0\0\0\0"
    "fc.RouteAnnounce"
    "route_id"
  }},
};

PROTOBUF_NOINLINE void RouteAnnounce::Clear() {
// @@protoc_insertion_point(message_clear_start:fc.RouteAnnounce)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.points_.Clear();
  _impl_.route_id_.ClearToEmpty();
  _impl_.type_ = 0;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* RouteAnnounce::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const RouteAnnounce& this_ = static_cast<const RouteAnnounce&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* RouteAnnounce::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const RouteAnnounce& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:fc.RouteAnnounce)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // string route_id = 1;
          if (!this_._internal_route_id().empty()) {
            const std::string& _s = this_._internal_route_id();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "fc.RouteAnnounce.route_id");
            target = stream->WriteStringMaybeAliased(1, _s, target);
          }

          // .fc.RouteAnnounce.RouteType type = 2;
          if (this_._internal_type() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteEnumToArray(
                2, this_._internal_type(), target);
          }

          // repeated .fc.RoutePoint points = 3;
          for (unsigned i = 0, n = static_cast<unsigned>(
                                   this_._internal_points_size());
               i < n; i++) {
            const auto& repfield = this_._internal_points().Get(i);
            target =
                ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
                    3, repfield, repfield.GetCachedSize(),
                    target, stream);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:fc.RouteAnnounce)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t RouteAnnounce::ByteSizeLong(const MessageLite& base) {
          const RouteAnnounce& this_ = static_cast<const RouteAnnounce&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t RouteAnnounce::ByteSizeLong() const {
          const RouteAnnounce& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:fc.RouteAnnounce)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // repeated .fc.RoutePoint points = 3;
            {
              total_size += 1UL * this_._internal_points_size();
              for (const auto& msg : this_._internal_points()) {
                total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
              }
            }
          }
           {
            // string route_id = 1;
            if (!this_._internal_route_id().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_route_id());
            }
            // .fc.RouteAnnounce.RouteType type = 2;
            if (this_._internal_type() != 0) {
              total_size += 1 +
                            ::_pbi::WireFormatLite::EnumSize(this_._internal_type());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void RouteAnnounce::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<RouteAnnounce*>(&to_msg);
  auto& from = static_cast<const RouteAnnounce&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:fc.RouteAnnounce)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_points()->MergeFrom(
      from._internal_points());
  if (!from._internal_route_id().empty()) {
    _this->_internal_set_route_id(from._internal_route_id());
  }
  if (from._internal_type() != 0) {
    _this->_impl_.type_ = from._impl_.type_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void RouteAnnounce::CopyFrom(const RouteAnnounce& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fc.RouteAnnounce)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void RouteAnnounce::InternalSwap(RouteAnnounce* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.points_.InternalSwap(&other->_impl_.points_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.route_id_, &other->_impl_.route_id_, arena);
  swap(_impl_.type_, other->_impl_.type_);
}

::google::protobuf::Metadata RouteAnnounce::GetMetadata() const {
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
        (::_pbi::AddDescriptors(&descriptor_table_FC_5fRoute_5fMessage_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
