local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    "onCCControlButtonIdleClicked",
    "onCCControlButtonWaveClicked",
    "onCCControlButtonJumpClicked",
    "onCCControlButtonFunkyClicked",
}

--[[
    
]]
local TestAnimationsLayer = Oop.class("TestAnimationsLayer", function(owner)
    return CCBHelper:create("TestAnimationsLayer", "ccb/TestAnimations.ccbi", funcs, owner)
end)

function TestAnimationsLayer:ctor()
    -- @TODO: constructor
end

function TestAnimationsLayer:onCCControlButtonIdleClicked(sender, event)
    -- @TODO: implement this
end

function TestAnimationsLayer:onCCControlButtonWaveClicked(sender, event)
    -- @TODO: implement this
end

function TestAnimationsLayer:onCCControlButtonJumpClicked(sender, event)
    -- @TODO: implement this
end

function TestAnimationsLayer:onCCControlButtonFunkyClicked(sender, event)
    -- @TODO: implement this
end

return TestAnimationsLayer