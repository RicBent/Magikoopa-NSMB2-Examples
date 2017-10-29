# Magikoopa NSMB2 Examples

Examples for using Magikoopa (https://github.com/RicBent/Magikoopa/) together with New Super Mario Bros. 2 to get full custom code.

### BlockItem
* All sprite blocks spawn a given item
* Shows how to replace an entire game function

### SizeModifier
* Sprites can be scaled via nybble 23
* Adds a custom implementaion for ActivePhysics::initWithStruct(Actor* owner, ActivePhysics::Info* info) which scales the hitboxes accordingly
* Hooks StageActor::afterCreate() to apply model scales
* Not as versatile as the NewerWii version of this:because only a few actors use the scale vector in onDraw() to scale their model(s)
