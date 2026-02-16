#include "doxy_smoke/cxx_api.hpp"

namespace doxy_smoke {

Buffer::Buffer() : buf_() {}
Buffer::Buffer(std::size_t initial) : buf_() { buf_.reserve(initial); }

void Buffer::append(const void* data, std::size_t n) {
    if (!data || n == 0) return;
    const uint8_t* p = static_cast<const uint8_t*>(data);
    buf_.insert(buf_.end(), p, p + n);
}

void Buffer::append(const std::string& s) {
    append(s.data(), s.size());
}

const uint8_t* Buffer::data() const noexcept {
    return buf_.empty() ? nullptr : buf_.data();
}

std::size_t Buffer::size() const noexcept {
    return buf_.size();
}

Mode build_mode() {
    return Mode::Safe;
}

} // namespace doxy_smoke
