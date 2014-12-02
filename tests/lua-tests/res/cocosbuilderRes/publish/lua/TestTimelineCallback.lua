local CCBHelper = import("Utils.CCBHelper")
local Oop = import("Oop.init")

local funcs = {
    
}

--[[
    self.helloLabel CCLabelTTF
]]
local TimelineCallbackTestLayer = Oop.class("TimelineCallbackTestLayer", function(owner)
    return CCBHelper:create("TimelineCallbackTestLayer", "ccb/TestTimelineCallback.ccbi", funcs, owner)
end)

function TimelineCallbackTestLayer:ctor()
    -- @TODO: constructor
end



return TimelineCallbackTestLayer