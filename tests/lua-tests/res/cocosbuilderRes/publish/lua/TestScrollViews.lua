local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    
}

--[[
    
]]
local TestScrollViewsLayer = Oop.class("TestScrollViewsLayer", function(owner)
    return CCBHelper:create("TestScrollViewsLayer", "ccb/TestScrollViews.ccbi", funcs, owner)
end)

function TestScrollViewsLayer:ctor()
    -- @TODO: constructor
end



return TestScrollViewsLayer