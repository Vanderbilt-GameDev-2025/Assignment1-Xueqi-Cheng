#include "register_types.h"
#include "EnhancedInputModule.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>  

using namespace godot;

void initialize_enhanced_input_module(ModuleInitializationLevel p_level) {
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_class<EnhancedInputModule>();
    }
}

void uninitialize_enhanced_input_module(ModuleInitializationLevel p_level) {
    // Cleanup logic if needed
}

extern "C" {
GDExtensionBool GDE_EXPORT EnhancedInputModule_library_init(
    GDExtensionInterfaceGetProcAddress p_get_proc_address,
    GDExtensionClassLibraryPtr p_library,
    GDExtensionInitialization *r_initialization) {

    static GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_enhanced_input_module);
    init_obj.register_terminator(uninitialize_enhanced_input_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}
