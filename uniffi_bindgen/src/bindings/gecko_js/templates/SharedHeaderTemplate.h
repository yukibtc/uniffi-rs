// This file was autogenerated by some hot garbage in the `uniffi` crate.
// Trust me, you don't want to mess with it!

#ifndef mozilla_dom_{{ context.namespace()|header_name_cpp(context) }}_Shared
#define mozilla_dom_{{ context.namespace()|header_name_cpp(context) }}_Shared

#include <functional>

#include "nsDebug.h"
#include "nsTArray.h"
#include "prnetdb.h"

#include "mozilla/Casting.h"
#include "mozilla/CheckedInt.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/Utf8.h"

#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Record.h"
#include "mozilla/dom/{{ context.namespace()|header_name_cpp(context) }}Binding.h"

{% include "FFIDeclarationsTemplate.h" %}

namespace mozilla {
namespace dom {

{% include "RustBufferHelper.h" %}

namespace {{ context.detail_name() }} {

{% for e in enums %}
template <>
struct ViaFfi<{{ e.name()|class_name_cpp(context) }}, uint32_t> {
  [[nodiscard]] static bool Lift(const uint32_t& aLowered, {{ e.name()|class_name_cpp(context) }}& aLifted) {
    switch (aLowered) {
      {% for variant in e.variants() -%}
      case {{ loop.index }}:
        aLifted = {{ e.name()|class_name_cpp(context) }}::{{ variant|enum_variant_cpp }};
        break;
      {% endfor -%}
      default:
        MOZ_ASSERT(false, "Unexpected enum case");
        return false;
    }
    return true;
  }

  [[nodiscard]] static uint32_t Lower(const {{ e.name()|class_name_cpp(context) }}& aLifted) {
    switch (aLifted) {
      {% for variant in e.variants() -%}
      case {{ e.name()|class_name_cpp(context) }}::{{ variant|enum_variant_cpp }}:
        return {{ loop.index }};
      {% endfor -%}
      default:
        MOZ_ASSERT(false, "Unknown raw enum value");
    }
    return 0;
  }
};

template <>
struct Serializable<{{ e.name()|class_name_cpp(context) }}> {
  [[nodiscard]] static bool ReadFrom(Reader& aReader, {{ e.name()|class_name_cpp(context) }}& aValue) {
    auto rawValue = aReader.ReadUInt32();
    return ViaFfi<{{ e.name()|class_name_cpp(context) }}, uint32_t>::Lift(rawValue, aValue);
  }

  static void WriteInto(Writer& aWriter, const {{ e.name()|class_name_cpp(context) }}& aValue) {
    aWriter.WriteUInt32(ViaFfi<{{ e.name()|class_name_cpp(context) }}, uint32_t>::Lower(aValue));
  }
};
{% endfor %}

{% for rec in dictionaries -%}
template <>
struct Serializable<{{ rec.name()|class_name_cpp(context) }}> {
  [[nodiscard]] static bool ReadFrom(Reader& aReader, {{ rec.name()|class_name_cpp(context) }}& aValue) {
    {%- for field in rec.members() %}
    if (!Serializable<{{ field.type_()|type_cpp(context) }}>::ReadFrom(aReader, aValue.{{ field.name()|field_name_cpp }})) {
      return false;
    }
    {%- endfor %}
    return true;
  }

  static void WriteInto(Writer& aWriter, const {{ rec.name()|class_name_cpp(context) }}& aValue) {
    {%- for field in rec.members() %}
    Serializable<{{ field.type_()|type_cpp(context) }}>::WriteInto(aWriter, aValue.{{ field.name()|field_name_cpp }});
    {%- endfor %}
  }
};
{% endfor %}

}  // namespace {{ context.detail_name() }}

}  // namespace dom
}  // namespace mozilla

#endif  // mozilla_dom_{{ context.namespace()|header_name_cpp(context) }}_Shared
