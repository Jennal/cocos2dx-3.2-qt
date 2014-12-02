local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    
}

--[[
    
]]
local TestSpritesLayer = Oop.class("TestSpritesLayer", function(owner)
    return CCBHelper:create("TestSpritesLayer", "ccb/TestSprites.ccbi", funcs, owner)
end)

function TestSpritesLayer:ctor()
    -- @TODO: constructor
end



return TestSpritesLayer