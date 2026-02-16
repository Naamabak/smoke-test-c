#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace doxy_smoke {

enum class Mode : uint8_t {
    Fast = 0,
    Safe = 1
};

class Buffer {
public:
    Buffer();
    explicit Buffer(std::size_t initial);

    void append(const void* data, std::size_t n);
    void append(const std::string& s);

    const uint8_t* data() const noexcept;
    std::size_t size() const noexcept;

private:
    std::vector<uint8_t> buf_;
};

/** @brief Returns the current build mode. */
Mode build_mode();

template <typename T>
T clamp(T v, T lo, T hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

} // namespace doxy_smoke
