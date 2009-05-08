DIRS = bddcmumps bddcpp lobpcg_driver multilevel mumps_adaptive 

##################################################################
# Targets
##################################################################

all: 
	@ \
        for i in ${DIRS}; \
        do \
          echo "Making $$i ..."; \
          (cd $$i && $(MAKE)); \
          echo ""; \
        done

clean: 
	@ \
        for i in ${DIRS}; \
        do \
          if [ -d $$i ]; \
          then \
            echo "Cleaning $$i ..."; \
            (cd $$i &&  $(MAKE) $@); \
          fi; \
        done
