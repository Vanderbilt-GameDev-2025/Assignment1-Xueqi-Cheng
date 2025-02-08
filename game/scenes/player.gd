extends CharacterBody2D

@onready var input_handler = $EnhancedInputModule

const BASE_SPEED = 300.0
const JUMP_VELOCITY = -600.0


func _physics_process(delta: float) -> void:
	# Get adjusted speed from EnhancedInputModule
	var speed = input_handler.get_speed()

	# Add gravity if not on the floor
	if not is_on_floor():
		velocity += get_gravity() * delta

	# Handle jumping
	if Input.is_action_just_pressed("ui_accept") and is_on_floor():
		velocity.y = JUMP_VELOCITY

	# Get movement direction
	var direction := Input.get_axis("ui_left", "ui_right")
	if direction:
		velocity.x = direction * speed  # Use modified speed
	else:
		velocity.x = move_toward(velocity.x, 0, BASE_SPEED)

	move_and_slide()
