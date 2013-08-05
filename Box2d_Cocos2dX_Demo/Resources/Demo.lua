local function main()
    --内存回收
    collectgarbage("setpause",100)  
    collectgarbage("setstepmul",5000)  
    local cclog=function ( ... )  
        print("LUA INFO:"..string.format(...))  
    end
    
    local function createLayer()
        local layer=CCLayer:create()
        local sprite=CCSprite:create("Icon.png")
        sprite:setPosition(100,100)
        layer:addChild(sprite)
        return layer
    end
    local scene=CCScene:create()
    scene:addChild(createLayer())
    CCDirector:sharedDirector():runWithScene(scene)
end

--CCLuaEngine 打印错误的函数
function __G__TRACKBACK__(msg)
    print("LUA ERROR:"..tostring(msg).."\n");
    print(debug.traceback());
end

--函數入口
xpcall(main,__G__TRACKBACK__);