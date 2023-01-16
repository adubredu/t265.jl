module t265

using CxxWrap

@wrapmodule(joinpath(@__DIR__, "lib/libT265"))

function __init__()
    @initcxx
end

include("get.jl")

export get_camera,
       get_translation,
       get_orientation,
       get_linear_velocity,
       get_linear_acceleration,
       get_angular_velocity,
       get_angular_acceleration

end
