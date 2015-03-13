//
//  RepeatEnum.h
//  RDTower
//
//  Created by changshuai on 15/3/11.
//
//

#ifndef RDTower_RepeatEnum_h
#define RDTower_RepeatEnum_h

typedef enum RepeatEnum{
    RepeatNone = 0,
    RepeatHorizon,
    RepeatVertical,
    RepeatAll
}RepeatEnum;

typedef enum RepeatEdge{
    Left = 0,
    Right,
    Top,
    Bottom
}RepeatEdge;
#endif
