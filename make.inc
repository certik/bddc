#*********************************
# the whole link sequence for BDDC
#*********************************
BDDCML_LINK_SEQUENCE = $(LIBBDDCML) $(BDDCML_LIBMUMPS) $(BDDCML_LIBPARMETIS) $(BDDCML_LIBMETIS) $(BDDCML_LIBSCALAPACK) $(BDDCML_LIBBLACS) \
                       $(BDDCML_LIBPORD) $(BDDCML_LIBLAPACK) $(BDDCML_LIBBLAS) $(BDDCML_BLOPEXLINK) $(BDDCML_LIBOTHERS) 
BDDCML_INC           = -I$(BDDCML_ROOT)/src

#*********** Compilers
BDDCML_MPFC = mpif90
BDDCML_MPFFLAGS = -g -C -Wall -fbounds-check
#BDDCML_MPFFLAGS = -O3

BDDCML_MPCC = mpicc
BDDCML_MPCFLAGS = -g -Wall
#BDDCML_MPCFLAGS = -O3

#*********** Library tools
BDDCML_AR = ar vr
BDDCML_RANLIB = ranlib

#**********Preprocessor defs for calling Fortran from C (-DAdd_ or -DAdd__ or -DUPPER)
BDDCML_CDEFS   = -DAdd_

#*********** Includes
# ParMetis
BDDCML_INCPARMETIS = -I$(PYTHONHPC)/include
# Metis
BDDCML_INCMETIS = -I$(PYTHONHPC)/include
# MUMPS
BDDCML_INCMUMPS    = -I$(PYTHONHPC)/include

#*********** Libraries
# library being created
BDDCML_ROOT         = $(HOME)/repos/bddc/xx
BDDCML_LIB_DIR      = $(BDDCML_ROOT)/lib
LIBBDDCML           = $(BDDCML_LIB_DIR)/libbddcml.a
# MUMPS
BDDCML_LIBMUMPS     = -L$(PYTHONHPC)/lib -ldmumps -lmumps_common -lpord
# ScaLAPACK
BDDCML_LIBSCALAPACK = -L$(PYTHONHPC)/lib -lscalapack
# BLACS
BDDCML_LIBBLACS     = -L$(PYTHONHPC)/lib
# BLAS
BDDCML_LIBBLAS      = -lblas
# LAPACK
BDDCML_LIBLAPACK    = -llapack
# ParMetis
BDDCML_LIBPARMETIS  = -L$(PYTHONHPC)/lib -lparmetis
# Metis
BDDCML_LIBMETIS     = -L$(PYTHONHPC)/lib -lmetis
# other needed libs ( e.g. -lmpi, -lpthread )
BDDCML_LIBOTHERS    = 

# BLOPEX objects
BDDCML_BLOPEXDIR = $(HOME)/repos/blopex
BDDCML_INCBLOPEX = \
   -I$(BDDCML_BLOPEXDIR)/blopex_serial_double/multivector \
   -I$(BDDCML_BLOPEXDIR)/blopex_serial_double/pcg_multi \
   -I$(BDDCML_BLOPEXDIR)/blopex_serial_double/matmultivec \
   -I$(BDDCML_BLOPEXDIR)/blopex_abstract/include
BDDCML_OBJBLOPEX = \
   $(BDDCML_BLOPEXDIR)/blopex_serial_double/multivector/multi_vector.o \
   $(BDDCML_BLOPEXDIR)/blopex_serial_double/pcg_multi/pcg_multi.o \
   $(BDDCML_BLOPEXDIR)/blopex_serial_double/matmultivec/matmultivec.o
BDDCML_LIBBLOPEX = -L$(BDDCML_BLOPEXDIR)/blopex_abstract/lib -lBLOPEX
BDDCML_BLOPEXLINK = $(BDDCML_OBJBLOPEX) $(BDDCML_LIBBLOPEX)

