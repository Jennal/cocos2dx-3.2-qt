local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    "onMenuTestClicked",
    "onSpriteTestClicked",
    "onButtonTestClicked",
    "onAnimationsTestClicked",
    "onParticleSystemTestClicked",
    "onScrollViewTestClicked",
    "onTimelineCallbackSoundClicked",
}

--[[
    self.mBurstSprite CCSprite
]]
local HelloCocosBuilderLayer = Oop.class("HelloCocosBuilderLayer", function(owner)
    return CCBHelper:create("HelloCocosBuilderLayer", "ccb/HelloCocosBuilder.ccbi", funcs, owner)
end)

function HelloCocosBuilderLayer:ctor()
    -- @TODO: constructor
end

function HelloCocosBuilderLayer:onMenuTestClicked(sender, event)
    -- @TODO: implement this
end

function HelloCocosBuilderLayer:onSpriteTestClicked(sender, event)
    -- @TODO: implement this
end

function HelloCocosBuilderLayer:onButtonTestClicked(sender, event)
    -- @TODO: implement this
end

function HelloCocosBuilderLayer:onAnimationsTestClicked(sender, event)
    -- @TODO: implement this
end

function HelloCocosBuilderLayer:onParticleSystemTestClicked(sender, event)
    -- @TODO: implement this
end

function HelloCocosBuilderLayer:onScrollViewTestClicked(sender, event)
    -- @TODO: implement this
end

function HelloCocosBuilderLayer:onTimelineCallbackSoundClicked(sender, event)
    -- @TODO: implement this
end

return HelloCocosBuilderLayer