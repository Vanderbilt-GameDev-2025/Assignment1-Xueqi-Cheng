#include "EnhancedInputModule.h"
#include <godot_cpp/classes/input_event_key.hpp>

void EnhancedInputModule::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_speed"), &EnhancedInputModule::get_speed);
}

EnhancedInputModule::EnhancedInputModule() {}

EnhancedInputModule::~EnhancedInputModule() {}

void EnhancedInputModule::_input(const Ref<InputEvent> &event) {
    Ref<InputEventKey> key_event = event;
    if (key_event.is_valid()) {
        int key_code = key_event->get_keycode();

        if (key_event->is_pressed()) {
            active_keys.insert(key_code);
        } else {
            active_keys.erase(key_code);
        }
    }
}

float EnhancedInputModule::get_speed() const {
    // Increase speed if SHIFT is pressed
    if (active_keys.count(KEY_SHIFT)) {
        return base_speed * speed_multiplier;
    }
    return base_speed;
}

