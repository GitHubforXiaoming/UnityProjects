// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_msg_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_msg_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_msg_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_msg_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_msg_2eproto;
namespace word3 {
class sendmsg;
class sendmsgDefaultTypeInternal;
extern sendmsgDefaultTypeInternal _sendmsg_default_instance_;
}  // namespace word3
PROTOBUF_NAMESPACE_OPEN
template<> ::word3::sendmsg* Arena::CreateMaybeMessage<::word3::sendmsg>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace word3 {

// ===================================================================

class sendmsg :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:word3.sendmsg) */ {
 public:
  sendmsg();
  virtual ~sendmsg();

  sendmsg(const sendmsg& from);
  sendmsg(sendmsg&& from) noexcept
    : sendmsg() {
    *this = ::std::move(from);
  }

  inline sendmsg& operator=(const sendmsg& from) {
    CopyFrom(from);
    return *this;
  }
  inline sendmsg& operator=(sendmsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const sendmsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const sendmsg* internal_default_instance() {
    return reinterpret_cast<const sendmsg*>(
               &_sendmsg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(sendmsg& a, sendmsg& b) {
    a.Swap(&b);
  }
  inline void Swap(sendmsg* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline sendmsg* New() const final {
    return CreateMaybeMessage<sendmsg>(nullptr);
  }

  sendmsg* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<sendmsg>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const sendmsg& from);
  void MergeFrom(const sendmsg& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(sendmsg* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "word3.sendmsg";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_msg_2eproto);
    return ::descriptor_table_msg_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgFieldNumber = 2,
    kIpFieldNumber = 3,
    kClientidFieldNumber = 1,
  };
  // required bytes msg = 2;
  bool has_msg() const;
  void clear_msg();
  const std::string& msg() const;
  void set_msg(const std::string& value);
  void set_msg(std::string&& value);
  void set_msg(const char* value);
  void set_msg(const void* value, size_t size);
  std::string* mutable_msg();
  std::string* release_msg();
  void set_allocated_msg(std::string* msg);

  // optional string ip = 3;
  bool has_ip() const;
  void clear_ip();
  const std::string& ip() const;
  void set_ip(const std::string& value);
  void set_ip(std::string&& value);
  void set_ip(const char* value);
  void set_ip(const char* value, size_t size);
  std::string* mutable_ip();
  std::string* release_ip();
  void set_allocated_ip(std::string* ip);

  // required int32 clientid = 1;
  bool has_clientid() const;
  void clear_clientid();
  ::PROTOBUF_NAMESPACE_ID::int32 clientid() const;
  void set_clientid(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:word3.sendmsg)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr ip_;
  ::PROTOBUF_NAMESPACE_ID::int32 clientid_;
  friend struct ::TableStruct_msg_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// sendmsg

// required int32 clientid = 1;
inline bool sendmsg::has_clientid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void sendmsg::clear_clientid() {
  clientid_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 sendmsg::clientid() const {
  // @@protoc_insertion_point(field_get:word3.sendmsg.clientid)
  return clientid_;
}
inline void sendmsg::set_clientid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000004u;
  clientid_ = value;
  // @@protoc_insertion_point(field_set:word3.sendmsg.clientid)
}

// required bytes msg = 2;
inline bool sendmsg::has_msg() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void sendmsg::clear_msg() {
  msg_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& sendmsg::msg() const {
  // @@protoc_insertion_point(field_get:word3.sendmsg.msg)
  return msg_.GetNoArena();
}
inline void sendmsg::set_msg(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:word3.sendmsg.msg)
}
inline void sendmsg::set_msg(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  msg_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:word3.sendmsg.msg)
}
inline void sendmsg::set_msg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:word3.sendmsg.msg)
}
inline void sendmsg::set_msg(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:word3.sendmsg.msg)
}
inline std::string* sendmsg::mutable_msg() {
  _has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_mutable:word3.sendmsg.msg)
  return msg_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* sendmsg::release_msg() {
  // @@protoc_insertion_point(field_release:word3.sendmsg.msg)
  if (!has_msg()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return msg_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void sendmsg::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  msg_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:word3.sendmsg.msg)
}

// optional string ip = 3;
inline bool sendmsg::has_ip() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void sendmsg::clear_ip() {
  ip_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& sendmsg::ip() const {
  // @@protoc_insertion_point(field_get:word3.sendmsg.ip)
  return ip_.GetNoArena();
}
inline void sendmsg::set_ip(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  ip_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:word3.sendmsg.ip)
}
inline void sendmsg::set_ip(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  ip_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:word3.sendmsg.ip)
}
inline void sendmsg::set_ip(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  ip_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:word3.sendmsg.ip)
}
inline void sendmsg::set_ip(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  ip_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:word3.sendmsg.ip)
}
inline std::string* sendmsg::mutable_ip() {
  _has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_mutable:word3.sendmsg.ip)
  return ip_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* sendmsg::release_ip() {
  // @@protoc_insertion_point(field_release:word3.sendmsg.ip)
  if (!has_ip()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return ip_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void sendmsg::set_allocated_ip(std::string* ip) {
  if (ip != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  ip_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ip);
  // @@protoc_insertion_point(field_set_allocated:word3.sendmsg.ip)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace word3

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_msg_2eproto