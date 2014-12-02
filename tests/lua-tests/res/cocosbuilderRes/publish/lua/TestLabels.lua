local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    
}

--[[
    
]]
local TestLabelsLayer = Oop.class("TestLabelsLayer", function(owner)
    return CCBHelper:create("TestLabelsLayer", "ccb/TestLabels.ccbi", funcs, owner)
end)

function TestLabelsLayer:ctor()
    -- @TODO: constructor
end



return TestLabelsLayer