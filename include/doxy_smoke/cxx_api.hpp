#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace doxy_smoke {

/**
 * @brief Specifies the operational mode as an 8-bit unsigned integer.
 */
enum class Mode : uint8_t {
    Fast = 0,
    Safe = 1
};

/**
 * @brief Represents a contiguous sequence of data in memory.
 */
class Buffer {
public:
    Buffer();
    /**
     * @brief Constructs a Buffer with a specified initial size.
     * @param initial The initial size of the buffer.
     */
    explicit Buffer(std::size_t initial);

    /**
     * @brief Appends a specified number of bytes from a data buffer.
     * @param data Pointer to the source buffer to be appended.
     * @param n Number of bytes to append from the buffer.
     */
    void append(const void* data, std::size_t n);
    /**
     * @brief Appends the specified string to the current instance.
     * @param s The string to be appended.
     */
    void append(const std::string& s);

    /**
     * @brief Access the underlying data buffer.
     * @return Pointer to the result, or NULL on failure.
     * @throws This function is noexcept and does not throw exceptions.
     */
    const uint8_t* data() const noexcept;
    /**
     * @brief Returns the number of elements in the container.
     * @return The current size as a std::size_t.
     * @throws None (noexcept).
     */
    std::size_t size() const noexcept;

private:
    std::vector<uint8_t> buf_;
};

/** @brief Returns the current build mode. */
Mode build_mode();

template <typename T>
/**
 * @brief Constrains a value between a specified lower and upper bound.
 * @tparam T The type of the values to be compared.
 * @param v The value to be clamped.
 * @param lo The lower boundary.
 * @param hi The upper boundary.
 * @return The clamped value of type T.
 */
T clamp(T v, T lo, T hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

} // namespace doxy_smoke
