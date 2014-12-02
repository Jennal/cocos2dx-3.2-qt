local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    "onBackClicked",
}

--[[
    owner.mTestTitleLabelTTF CCLabelTTF
]]
local TestHeaderLayer = Oop.class("TestHeaderLayer", function(owner)
    return CCBHelper:create("TestHeaderLayer", "ccb/TestHeader.ccbi", funcs, owner)
end)

function TestHeaderLayer:ctor()
    -- @TODO: constructor
end

function TestHeaderLayer:onBackClicked(sender, event)
    -- @TODO: implement this
end

return TestHeaderLayer