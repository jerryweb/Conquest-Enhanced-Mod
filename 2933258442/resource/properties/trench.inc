;SDL
game_entity
	{props "trench"}
	{obstacleid "trench_wall"}
	{collider "construction"}
	{NoCastShadows}
	{extender "land_patch"
		{AlignEnabled 1}
		{AlignStacked 0}
		{AlignVolumes 1}
		{TerrainType "ground" "ground"}
		{RemoveEntities 1}
		{BigKernel}
	}
	(define "volume"
		{Volume %0 {thickness 60} {tags "body"} {able {contact 0} {obstacle 1}}}
	)
	(define "foxhole"
		{Volume %0 {thickness 60} {tags "body"} {able clear {obstacle 1} {blast 1}}}
	)
	(define "boneLand"
		{bone %0 {parameters "Ground;Land;Align;"}}
	)
	(define "boneLand2"
		{bone %0 {parameters "Ground;Land;"}}
	)
	(define "boneAlign"
		{bone %0 {parameters "Align;"}}
	)

	{lodclass "decor_trench"}