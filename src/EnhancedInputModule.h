#ifndef ENHANCED_INPUT_MODULE_H
#define ENHANCED_INPUT_MODULE_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input_event.hpp>  
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <unordered_set>

using namespace godot;

class EnhancedInputModule : public Node {
    GDCLASS(EnhancedInputModule, Node)

private:
    float base_speed = 200.0f;  // Default speed
    float speed_multiplier = 5.0f; // Speed multiplier when combo is pressed
    std::unordered_set<int> active_keys; // Stores currently pressed keys

protected:
    static void _bind_methods();

public:
    EnhancedInputModule();
    ~EnhancedInputModule();

    void _input(const Ref<InputEvent> &event) override;
    float get_speed() const; // Returns the adjusted speed
};

#endif // ENHANCED_INPUT_MODULE_H

