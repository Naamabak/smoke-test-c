#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace doxy_smoke {

/**
 * @brief Mode.
 */
enum class Mode : uint8_t {
    Fast = 0,
    Safe = 1
};

/**
 * @brief Buffer.
 */
class Buffer {
public:
    /**
     * @brief Default constructor for the Buffer class.
     */
    Buffer();
    /**
     * @brief Constructs a Buffer with a specified initial size.
     * @param initial The starting size of the buffer.
     */
    explicit Buffer(std::size_t initial);

    /**
     * @brief Appends a specified number of bytes from a data buffer.
     * @param data Pointer to the memory buffer to be appended.
     * @param n Number of bytes to append from the buffer.
     */
    void append(const void* data, std::size_t n);
    /**
     * @brief Appends a string to the current object.
     * @param s The string to be appended.
     */
    void append(const std::string& s);

    /**
     * @brief Provides read-only access to the underlying data buffer.
     * @return A pointer to the constant uint8_t data.
     * @throws This function is noexcept and does not throw exceptions.
     */
    const uint8_t* data() const noexcept;
    /**
     * @brief Returns the number of elements in the container.
     * @throws This function is noexcept and does not throw exceptions.
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
