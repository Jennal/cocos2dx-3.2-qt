#ifndef __CCRepeat9Sprite_H__
#define __CCRepeat9Sprite_H__

#include "cocos2d.h"
#include "../CCControlUtils.h"
#include "RepeatNode.h"
#include "RepeatEnum.h"

using namespace cocos2d;

NS_CC_EXT_BEGIN

class Repeat9Sprite : public Node
{
public:
    /**
     * @js ctor
     */
    Repeat9Sprite();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~Repeat9Sprite();
    
public:
    static Repeat9Sprite* create();
    
    /**
     * Creates a 9-slice sprite with a texture file, a delimitation zone and
     * with the specified cap insets.
     *
     * @see initWithFile(const char *file, const Rect& rect, const Rect& capInsets)
     */
    static Repeat9Sprite* create(const std::string& file, const Rect& rect,  const Rect& capInsets);
    
    /**
     * Creates a 9-slice sprite with a texture file. The whole texture will be
     * broken down into a 3×3 grid of equal blocks.
     *
     * @see initWithFile(const Rect& capInsets, const char *file)
     */
    static Repeat9Sprite* create(const Rect& capInsets, const std::string& file);
    
    /**
     * Creates a 9-slice sprite with a texture file and a delimitation zone. The
     * texture will be broken down into a 3×3 grid of equal blocks.
     *
     * @see initWithFile(const char *file, const Rect& rect)
     */
    static Repeat9Sprite* create(const std::string& file, const Rect& rect);
    
    /**
     * Creates a 9-slice sprite with a texture file. The whole texture will be
     * broken down into a 3×3 grid of equal blocks.
     *
     * @see initWithFile(const char *file)
     */
    static Repeat9Sprite* create(const std::string& file);
    
    /**
     * Creates a 9-slice sprite with an sprite frame.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @see initWithSpriteFrame(SpriteFrame *spriteFrame)
     */
    static Repeat9Sprite* createWithSpriteFrame(SpriteFrame* spriteFrame);
    
    /**
     * Creates a 9-slice sprite with an sprite frame and the centre of its zone.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @see initWithSpriteFrame(SpriteFrame *spriteFrame, const Rect& capInsets)
     */
    static Repeat9Sprite* createWithSpriteFrame(SpriteFrame* spriteFrame, const Rect& capInsets);
    
    /**
     * Creates a 9-slice sprite with an sprite frame name.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @see initWithSpriteFrameName(const char *spriteFrameName)
     */
    static Repeat9Sprite* createWithSpriteFrameName(const std::string& spriteFrameName);
    
    /**
     * Creates a 9-slice sprite with an sprite frame name and the centre of its
     * zone.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @see initWithSpriteFrameName(const char *spriteFrameName, const Rect& capInsets)
     */
    static Repeat9Sprite* createWithSpriteFrameName(const std::string& spriteFrameName, const Rect& capInsets);
    
    /**
     * Initializes a 9-slice sprite with a texture file, a delimitation zone and
     * with the specified cap insets.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param file The name of the texture file.
     * @param rect The rectangle that describes the sub-part of the texture that
     * is the whole image. If the shape is the whole texture, set this to the
     * texture's full rect.
     * @param capInsets The values to use for the cap insets.
     */
    virtual bool initWithFile(const std::string& file, const Rect& rect,  const Rect& capInsets);
    
    /**
     * Initializes a 9-slice sprite with a texture file and a delimitation zone. The
     * texture will be broken down into a 3×3 grid of equal blocks.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param file The name of the texture file.
     * @param rect The rectangle that describes the sub-part of the texture that
     * is the whole image. If the shape is the whole texture, set this to the
     * texture's full rect.
     */
    virtual bool initWithFile(const std::string& file, const Rect& rect);
    
    /**
     * Initializes a 9-slice sprite with a texture file and with the specified cap
     * insets.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param file The name of the texture file.
     * @param capInsets The values to use for the cap insets.
     */
    virtual bool initWithFile(const Rect& capInsets, const std::string& file);
    
    /**
     * Initializes a 9-slice sprite with a texture file. The whole texture will be
     * broken down into a 3×3 grid of equal blocks.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param file The name of the texture file.
     */
    virtual bool initWithFile(const std::string& file);
    
    /**
     * Initializes a 9-slice sprite with an sprite frame and with the specified
     * cap insets.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param spriteFrame The sprite frame object.
     * @param capInsets The values to use for the cap insets.
     */
    virtual bool initWithSpriteFrame(SpriteFrame* spriteFrame, const Rect& capInsets);
    
    /**
     * Initializes a 9-slice sprite with an sprite frame.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param spriteFrame The sprite frame object.
     */
    virtual bool initWithSpriteFrame(SpriteFrame* spriteFrame);
    
    /**
     * Initializes a 9-slice sprite with an sprite frame name and with the specified
     * cap insets.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param spriteFrameName The sprite frame name.
     * @param capInsets The values to use for the cap insets.
     */
    virtual bool initWithSpriteFrameName(const std::string& spriteFrameName, const Rect& capInsets);
    
    /**
     * Initializes a 9-slice sprite with an sprite frame name.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param spriteFrameName The sprite frame name.
     */
    virtual bool initWithSpriteFrameName(const std::string& spriteFrameName);
    
    virtual bool init();
    virtual bool initWithBatchNode(SpriteBatchNode* batchnode, const Rect& rect, bool rotated, const Rect& capInsets);
    virtual bool initWithBatchNode(SpriteBatchNode* batchnode, const Rect& rect, const Rect& capInsets);
    
    /**
     * Creates and returns a new sprite object with the specified cap insets.
     * You use this method to add cap insets to a sprite or to change the existing
     * cap insets of a sprite. In both cases, you get back a new image and the
     * original sprite remains untouched.
     *
     * @param capInsets The values to use for the cap insets.
     */
    Repeat9Sprite* resizableSpriteWithCapInsets(const Rect& capInsets);
    
    virtual bool updateWithBatchNode(SpriteBatchNode* batchnode, const Rect& rect, bool rotated, const Rect& capInsets);
    virtual void setSpriteFrame(SpriteFrame * spriteFrame);
    
    // overrides
    virtual void setContentSize(const Size & size) override;

    virtual void visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags) override;
    virtual void setOpacityModifyRGB(bool bValue) override;
    virtual bool isOpacityModifyRGB(void) const override;
    virtual void setOpacity(GLubyte opacity) override;
    virtual void setColor(const Color3B& color) override;
    virtual void updateDisplayedOpacity(GLubyte parentOpacity) override;
    virtual void updateDisplayedColor(const Color3B& parentColor) override;
    
    bool isRepeatEdge(RepeatEdge edge);
    void setRepeatMode(RepeatEnum mode);
    void setRepeatModeToEdge(bool repeat, RepeatEdge edge);
protected:
    void updateCapInset();
    void updatePositions();
    
    bool _spritesGenerated;
    Rect _spriteRect;
    bool   _spriteFrameRotated;
    Rect _capInsetsInternal;
    bool _positionsAreDirty;
    
    SpriteBatchNode* _scale9Image;
    Sprite* _topLeft;
    RepeatNode* _top;
    Sprite* _topRight;
    RepeatNode* _left;
    Sprite* _centre;
    RepeatNode* _right;
    Sprite* _bottomLeft;
    RepeatNode* _bottom;
    Sprite* _bottomRight;
    RepeatEnum _leftMode;
    RepeatEnum _topMode;
    RepeatEnum _rightMode;
    RepeatEnum _bottomMode;
    
    bool _opacityModifyRGB;
    
    /** Original sprite's size. */
    CC_SYNTHESIZE_READONLY(Size, _originalSize, OriginalSize);
    /** Prefered sprite's size. By default the prefered size is the original size. */
    
    //if the preferredSize component is given as -1, it is ignored
    CC_PROPERTY(Size, _preferredSize, PreferredSize);
    /**
     * The end-cap insets.
     * On a non-resizeable sprite, this property is set to CGRect::ZERO; the sprite
     * does not use end caps and the entire sprite is subject to stretching.
     */
    CC_PROPERTY(Rect, _capInsets, CapInsets);
    /** Sets the left side inset */
    CC_PROPERTY(float, _insetLeft, InsetLeft);
    /** Sets the top side inset */
    CC_PROPERTY(float, _insetTop, InsetTop);
    /** Sets the right side inset */
    CC_PROPERTY(float, _insetRight, InsetRight);
    /** Sets the bottom side inset */
    CC_PROPERTY(float, _insetBottom, InsetBottom);
};

NS_CC_EXT_END

#endif // __CCRepeat9Sprite_H__
