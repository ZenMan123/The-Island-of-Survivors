#pragma once

#include "functions.hpp"

#include <vector>


// Associative object storage
template <typename ValueType>
class AssociativeStorage {
    std::vector<size_t> values_index_;
    std::vector<size_t> free_value_id_;
    std::vector<std::pair<size_t, ValueType>> values_;

public:
    using Iterator = typename std::vector<std::pair<size_t, ValueType>>::iterator;
    using ConstIterator = typename std::vector<std::pair<size_t, ValueType>>::const_iterator;

    // Constructors
    AssociativeStorage() noexcept {
    }

    AssociativeStorage(const AssociativeStorage<ValueType>& other)
        : values_index_(other.values_index_)
        , free_value_id_(other.free_value_id_)
        , values_(other.values_)
    {}

    AssociativeStorage(AssociativeStorage<ValueType>&& other) noexcept {
        swap(other);
    }

    // Operators
    AssociativeStorage<ValueType>& operator=(AssociativeStorage<ValueType> other)& {
        swap(other);
        return *this;
    }

    ValueType& operator[](size_t id) {
        ENSURE(contains(id), OutOfRange, "invalid value id");

        return values_[values_index_[id]].second;
    }

    const ValueType& operator[](size_t id) const {
        ENSURE(contains(id), OutOfRange, "invalid value id");

        return values_[values_index_[id]].second;
    }

    // Getters
    size_t get_memory_id(size_t id) const {
        ENSURE(contains(id), OutOfRange, "invalid value id");

        return values_index_[id];
    }

    size_t get_id(size_t memory_id) const {
        ENSURE(memory_id < values_.size(), OutOfRange, "invalid memory id");

        return values_[memory_id].first;
    }

    // Common functions
    bool contains(size_t id) const noexcept {
        return id < values_index_.size() && values_index_[id] < std::numeric_limits<size_t>::max();
    }

    bool contains_memory(size_t memory_id) const noexcept {
        return memory_id < values_.size();
    }

    size_t size() const noexcept {
        return values_.size();
    }

    bool empty() const noexcept {
        return values_.empty();
    }

    Iterator begin() noexcept {
        return values_.begin();
    }

    Iterator end() noexcept {
        return values_.end();
    }

    ConstIterator begin() const noexcept {
        return values_.begin();
    }

    ConstIterator end() const noexcept {
        return values_.end();
    }

    // Modifiers
    void erase(size_t id) {
        ENSURE(contains(id), OutOfRange, "invalid value id");

        free_value_id_.push_back(id);

        values_index_[values_.back().first] = values_index_[id];
        std::swap(values_[values_index_[id]], values_.back());

        values_.pop_back();
        values_index_[id] = std::numeric_limits<size_t>::max();
    }

    void clear() noexcept {
        values_index_.clear();
        free_value_id_.clear();
        values_.clear();
    }

    size_t insert(ValueType value) {
        size_t free_value_id = values_index_.size();
        if (free_value_id_.empty()) {
            values_index_.push_back(values_.size());
        }
        else {
            free_value_id = free_value_id_.back();
            free_value_id_.pop_back();
            values_index_[free_value_id] = values_.size();
        }

        values_.push_back({ free_value_id, std::move(value) });
        return free_value_id;
    }
    
    void swap(AssociativeStorage& other) noexcept {
        values_index_.swap(other.values_index_);
        free_value_id_.swap(other.free_value_id_);
        values_.swap(other.values_);
    }
};
