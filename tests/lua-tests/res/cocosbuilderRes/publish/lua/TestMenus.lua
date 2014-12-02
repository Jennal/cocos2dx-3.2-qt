local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    "onMenuItemAClicked",
    "onMenuItemBClicked",
    "pressedC:",
}

--[[
    self.mMenuItemStatusLabelBMFont CCLabelBMFont
]]
local TestMenusLayer = Oop.class("TestMenusLayer", function(owner)
    return CCBHelper:create("TestMenusLayer", "ccb/TestMenus.ccbi", funcs, owner)
end)

function TestMenusLayer:ctor()
    -- @TODO: constructor
end

function TestMenusLayer:onMenuItemAClicked(sender, event)
    -- @TODO: implement this
end

function TestMenusLayer:onMenuItemBClicked(sender, event)
    -- @TODO: implement this
end

function TestMenusLayer:pressedC:(sender, event)
    -- @TODO: implement this
end

return TestMenusLayer