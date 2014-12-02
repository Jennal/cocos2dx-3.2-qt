local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    
}

--[[
    
]]
local TestParticleSystemsLayer = Oop.class("TestParticleSystemsLayer", function(owner)
    return CCBHelper:create("TestParticleSystemsLayer", "ccb/TestParticleSystems.ccbi", funcs, owner)
end)

function TestParticleSystemsLayer:ctor()
    -- @TODO: constructor
end



return TestParticleSystemsLayer