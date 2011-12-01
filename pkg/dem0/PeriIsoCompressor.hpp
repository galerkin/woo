// 2009 © Václav Šmilauer <eudoxos@arcig.cz> 

#pragma once

#include<yade/pkg/common/BoundaryController.hpp>

class PeriIsoCompressor: public BoundaryController{
	Real avgStiffness; Real maxDisplPerStep; Vector3r sumForces, sigma; 
	Real currUnbalanced;
	public:
		void action();
	YADE_CLASS_BASE_DOC_ATTRS_CTOR_PY(PeriIsoCompressor,BoundaryController,"Compress/decompress cloud of spheres by controlling periodic cell size until it reaches prescribed average stress, then moving to next stress value in given stress series.",
		((vector<Real>,stresses,,,"Stresses that should be reached, one after another"))
		((Real,charLen,-1.,,"Characteristic length, should be something like mean particle diameter (default -1=invalid value))"))
		((Real,maxSpan,-1.,,"Maximum body span in terms of bbox, to prevent periodic cell getting too small. |ycomp|"))
		((Real,maxUnbalanced,1e-4,,"if actual unbalanced force is smaller than this number, the packing is considered stable,"))
		((int,globalUpdateInt,20,,"how often to recompute average stress, stiffness and unbalanced force"))
		((size_t,state,0,,"Where are we at in the stress series"))
		((string,doneHook,"",,"Python command to be run when reaching the last specified stress"))
		((bool,keepProportions,true,,"Exactly keep proportions of the cell (stress is controlled based on average, not its components")),
		/*ctor*/
			currUnbalanced=-1;
			avgStiffness=-1;
			maxDisplPerStep=-1;
			sumForces=Vector3r::Zero();
			sigma=Vector3r::Zero();
		,
		/*py*/
			.def_readonly("currUnbalanced",&PeriIsoCompressor::currUnbalanced,"Current value of unbalanced force")
			.def_readonly("sigma",&PeriIsoCompressor::sigma,"Current stress value")
	);
	DECLARE_LOGGER;
};
REGISTER_SERIALIZABLE(PeriIsoCompressor);
/* Engine for independently controlling stress or strain in periodic simulations.

strainStress contains absolute values for the controlled quantity, and stressMask determines
meaning of those values (0 for strain, 1 for stress): e.g. ( 1<<0 | 1<<2 ) = 1 | 4 = 5 means that
strainStress[0] and strainStress[2] are stress values, and strainStress[1] is strain.

See scripts/test/periodic-triax.py for a simple example.

*/

class PeriTriaxController: public BoundaryController{
	public:
		virtual void action();
		void strainStressStiffUpdate();
	YADE_CLASS_BASE_DOC_ATTRS(PeriTriaxController,BoundaryController,"Engine for independently controlling stress or strain in periodic simulations.\n\n``strainStress`` contains absolute values for the controlled quantity, and ``stressMask`` determines meaning of those values (0 for strain, 1 for stress): e.g. ``( 1<<0 | 1<<2 ) = 1 | 4 = 5`` means that ``strainStress[0]`` and ``strainStress[2]`` are stress values, and ``strainStress[1]`` is strain. \n\nSee scripts/test/periodic-triax.py for a simple example.",
		((bool,reversedForces,false,,"For some constitutive laws (practicaly all laws based on ScGeom), normalForce and shearForce on interactions are in the reverse sense and this flag must be true (mandatory). see `bugreport <https://bugs.launchpad.net/yade/+bug/493102>`_"))
		((bool,dynCell,false,,"Imposed stress can be controlled using the packing stiffness or by applying the laws of dynamic (dynCell=true). Don't forget to assign a :yref:`mass<PeriTriaxController.mass>` to the cell."))
		((Vector3r,goal,Vector3r::Zero(),,"Desired stress or strain values (depending on stressMask), strains defined as ``strain(i)=log(Fii)``.\n\n.. warning:: Strains are relative to the :yref:`O.cell.refSize<Cell.refSize>` (reference cell size), not the current one (e.g. at the moment when the new strain value is set)."))
		((int,stressMask,((void)"all strains",0),,"mask determining strain/stress (0/1) meaning for goal components"))
		((Vector3r,maxStrainRate,Vector3r(1,1,1),,"Maximum strain rate of the periodic cell."))
		((Real,maxUnbalanced,1e-4,,"maximum unbalanced force."))
		((Real,absStressTol,1e3,,"Absolute stress tolerance"))
		((Real,relStressTol,3e-5,,"Relative stress tolerance"))
		((Real,growDamping,.25,,"Damping of cell resizing (0=perfect control, 1=no control at all); see also ``wallDamping`` in :yref:`TriaxialStressController`."))
		((int,globUpdate,5,,"How often to recompute average stress, stiffness and unbalaced force."))
		((string,doneHook,,,"python command to be run when the desired state is reached"))
		((Vector3r,maxBodySpan,Vector3r::Zero(),,"maximum body dimension |ycomp|"))
		((Matrix3r,stressTensor,Matrix3r::Zero(),,"average stresses, updated at every step (only every globUpdate steps recomputed from interactions if !dynCell)"))
		((Vector3r,stress,Vector3r::Zero(),,"diagonal terms of the stress tensor"))
		((Vector3r,strain,Vector3r::Zero(),,"cell strain |yupdate|"))
		((Vector3r,strainRate,Vector3r::Zero(),,"cell strain rate |yupdate|"))
		((Vector3r,stiff,Vector3r::Zero(),,"average stiffness (only every globUpdate steps recomputed from interactions) |yupdate|"))
		((Real,currUnbalanced,NaN,,"current unbalanced force (updated every globUpdate) |yupdate|"))
		((Vector3r,prevGrow,Vector3r::Zero(),,"previous cell grow"))
		((Real,mass,NaN,,"mass of the cell (user set); if not set and :yref:`dynCell<PeriTriaxController.dynCell>` is used, it will be computed as sum of masses of all particles."))
		((Real,externalWork,0,,"Work input from boundary controller."))
		((int,velGradWorkIx,-1,(Attr::hidden|Attr::noSave),"Index for work done by velocity gradient, if tracking energy"))
	);
	DECLARE_LOGGER;
};
REGISTER_SERIALIZABLE(PeriTriaxController);
