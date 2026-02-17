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
     * @brief Buffer.
     */
    Buffer();
    /**
     * @brief Buffer.
     * @param initial Parameter of type inferred from signature.
     */
    explicit Buffer(std::size_t initial);

    /**
     * @brief Append.
     * @param data Parameter of type inferred from signature.
     * @param n Parameter of type inferred from signature.
     */
    void append(const void* data, std::size_t n);
    /**
     * @brief Add the specified string to the end of the existing sequence.
     * @param s The string to be appended.
     */
    void append(const std::string& s);

    /**
     * @brief Access the underlying byte sequence.
     * @return A pointer to the constant byte data.
     */
    const uint8_t* data() const noexcept;
    /**
     * @brief Retrieve the current number of elements in the container.
     */
    std::size_t size() const noexcept;

private:
    std::vector<uint8_t> buf_;
};

/** @brief Returns the current build mode. */
Mode build_mode();

template <typename T>
/**
 * @tparam T The type of the values to be compared.
 * @brief Constrain a value within a specified range.
 * @param v The value to be clamped.
 * @param lo The lower bound of the range.
 * @param hi The upper bound of the range.
 * @return The value of v restricted to the interval [lo, hi].
 */
T clamp(T v, T lo, T hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

} // namespace doxy_smoke
