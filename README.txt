$Id 
README.txt
==========

INSTALLATION
============
1) Install the module.
2) Go to /admin/settings/closure_compiler, enable the service. Enable js aggregation if it's not already enabled.


CHANGELOG
==========
* Added Google Closure Compiler Application support (java based local compiling) 
* Performance improvements: For checking whether a file has been processed before, only reading the sufficient number of bytes as opposed to
whole file