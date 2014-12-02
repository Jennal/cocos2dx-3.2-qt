local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    "onCCControlButtonClicked",
}

--[[
    self.mCCControlEventLabel CCLabelBMFont
]]
local TestButtonsLayer = Oop.class("TestButtonsLayer", function(owner)
    return CCBHelper:create("TestButtonsLayer", "ccb/TestButtons.ccbi", funcs, owner)
end)

function TestButtonsLayer:ctor()
    -- @TODO: constructor
end

function TestButtonsLayer:onCCControlButtonClicked(sender, event)
    -- @TODO: implement this
end

return TestButtonsLayer