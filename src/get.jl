function get_camera()
    camera = t265.T265()
    return camera 
end 

function get_translation(camera)
    pose = t265.get_translation(camera)
    return pose 
end

# Quaternion w, x, y, z
function get_orientation(camera)
    pose = t265.get_orientation(camera)
    return pose 
end

function get_linear_velocity(camera)
    pose = t265.get_linear_velocity(camera)
    return pose 
end

function get_linear_acceleration(camera)
    pose = t265.get_linear_acceleration(camera)
    return pose 
end

function get_angular_velocity(camera)
    pose = t265.get_angular_velocity(camera)
    return pose 
end

function get_angular_acceleration(camera)
    pose = t265.get_angular_acceleration(camera)
    return pose 
end
