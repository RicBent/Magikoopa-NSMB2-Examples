typedef unsigned char   u8;
typedef unsigned int    u32;


// TODO: Replace helper structs with actual classes later

typedef struct
{
    u8 unk0[0x58];      // _0
    
    float scalex;       // _58
    float scaley;       // _5C
    float scalez;       // _60
    
    u8 unk1[0x118];     // _64
    
    u8 spriteData[10];  // _17C
} Actor;


typedef struct
{
    float x;
    float y;
} Vec2;

typedef struct
{
    u8 unk0[0xC];       // _0
    Actor* owner;       // _C
    u8 unk1[0xC];       // _10

    Vec2 distToCenter;  // _1C
    Vec2 distToEdge;    // _24
    u32 initData0;      // _2C
    u32 initData1;      // _30
    u32 initData2;      // _34
    u32 initData3;      // _38
    void* callback;     // _3C

    u8 unk2[0x73];      // _40

    u8 unk3;            // _B6
} ActivePhysics;

typedef struct          // Size: 0x24
{
    Vec2 distToCenter;  // _0
    Vec2 distToEdge;    // _8
    
    u32 unk0;           // _10
    u32 unk1;           // _14
    u32 someBitfield;   // _18
    u32 unk3;           // _1C
    
    void* callback;     // _20
} AP_InitData;


const float actorScales[] =
{
    1.0f, 0.25f, 0.5f, 0.75f, 1.0f, 1.25f, 1.5f, 1.75f, 2.0f, 2.5f, 3.0f, 4.0f, 5.0f, 7.5f, 10.0f
};

void ModifyGlobalSizes(Actor* actor)
{    
    u8 scaleIndex = actor->spriteData[9];
    
    if (scaleIndex == 0)
        return;
    
    float scale = actorScales[scaleIndex];
    
    actor->scalex *= scale;
    actor->scaley *= scale;
    actor->scalez *= scale;
}    

void initActivePhysicsWithStruct(ActivePhysics* ap, Actor* actor, AP_InitData* initData)
{
    ap->owner = actor;

    ap->distToCenter = initData->distToCenter;
    ap->distToEdge = initData->distToEdge;
    ap->initData0 = initData->unk0;
    ap->initData1 = initData->unk1;
    ap->initData2 = initData->someBitfield;
    ap->initData3 = initData->unk3;
    ap->callback = initData->callback;

    ap->unk3 = 0;


    u8 scaleIndex = actor->spriteData[9];

    if (scaleIndex == 0)
        return;

    float scale = actorScales[scaleIndex];

    ap->distToCenter.x *= scale;
    ap->distToCenter.y *= scale;
    ap->distToEdge.x *= scale;
    ap->distToEdge.y *= scale;
}
