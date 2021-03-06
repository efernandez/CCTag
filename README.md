CCTag library
===================


Detection of CCTag markers made up of concentric circles. Implementations in both CPU and GPU.

See paper: "Detection and Accurate Localization of Circular Fiducials under Highly Challenging Conditions." Lilian Calvet, Pierre Gurdjos, Carsten Griwodz and Simone Gasparini. CVPR 2016.


Marker library
---------

Markers to print are located [here](markersToPrint). 

**WARNING**
Please respect the provided margins. The reported detection rate and localization accuracy are valid with completely planar support: be careful not to use bent support (e.g. corrugated sheet of paper).

The four rings CCTags will be available soon.

Building
--------

See [BUILD](BUILD.md) text file.

Continuous integration: 
 - [![Build Status](https://travis-ci.org/poparteu/CCTag.svg?branch=master)](https://travis-ci.org/poparteu/CCTag) master branch.
 - [![Build Status](https://travis-ci.org/poparteu/CCTag.svg?branch=develop)](https://travis-ci.org/poparteu/CCTag) develop branch.

Running
-------

Once compiled, you might want to run the CCTag detection on a sample image:
```bash
$ build/src/detection -n 3 -i sample/01.png
``` 
For the library interface, see [ICCTag.hpp](src/cctag/ICCTag.hpp).

License
-------

CCTag is licensed under [MPL v2 license](LICENSE.md).

Authors
-------

Lilian Calvet (CPU, lilian.calvet@gmail.com)  
Carsten Griwodz (GPU, griff@simula.no)  
Stian Vrba (CPU, vrba@mixedrealities.no)  
Cyril Pichard (pih@mikrosimage.eu)


Acknowledgments
---------

This has been developed in the context of the European project [POPART](http://www.popartproject.eu/) founded by European Union’s Horizon 2020 research and innovation programme under grant agreement No 644874.
