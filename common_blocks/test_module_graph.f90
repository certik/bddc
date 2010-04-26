program test_module_graph
! tester of module graph

use module_graph

implicit none

integer,parameter :: idgraph = 21

integer  :: nvertex, nedge, graphtype
integer  ::             lxadj
integer,allocatable  ::  xadj(:)
integer  ::             ladjncy
integer,allocatable  ::  adjncy(:)
integer  ::             ladjwgt
integer,allocatable  ::  adjwgt(:)
integer  ::            lcomponents
integer,allocatable  :: components(:)
integer  ::    ncomponents

integer :: i

      write(*,*) 'Test on connected graph with 1 component.'
! GRAPH - list of neighbours for elements
      open (unit=idgraph,file='test_module_graph_input_1.txt',status='old',form='formatted')
      rewind idgraph

! read initial line in the file with graph
      call graph_read_dimensions(idgraph,nvertex,nedge,graphtype,lxadj,ladjncy,ladjwgt)
      allocate(adjncy(ladjncy))
      allocate(adjwgt(ladjwgt))
      allocate(xadj(lxadj))
      call graph_read(idgraph,nvertex,nedge,graphtype,xadj,lxadj,adjncy,ladjncy,adjwgt,ladjwgt)
      close(idgraph)

      lcomponents = nvertex
      allocate(components(lcomponents))

      call graph_components(nvertex,xadj,lxadj,adjncy,ladjncy,components,lcomponents,ncomponents)
      write(*,*) 'ncomponents =', ncomponents
      write(*,*) 'vertex             component'
      do i = 1,nvertex
         write(*,*) i, components(i)
      end do
      if (all(components.eq.(/ 1, 1, 1, 1 /))) then
         write(*,*) 'Components seem O.K.'
      else   
         write(*,*) 'Components seem WRONG.'
      end if

      deallocate(components)
      deallocate(adjncy)
      deallocate(adjwgt)
      deallocate(xadj)

      write(*,*) 'Test on disconnected graph of 2 components.'
! GRAPH - list of neighbours for elements
      open (unit=idgraph,file='test_module_graph_input_2.txt',status='old',form='formatted')
      rewind idgraph

! read initial line in the file with graph
      call graph_read_dimensions(idgraph,nvertex,nedge,graphtype,lxadj,ladjncy,ladjwgt)
      allocate(adjncy(ladjncy))
      allocate(adjwgt(ladjwgt))
      allocate(xadj(lxadj))
      call graph_read(idgraph,nvertex,nedge,graphtype,xadj,lxadj,adjncy,ladjncy,adjwgt,ladjwgt)
      close(idgraph)

      lcomponents = nvertex
      allocate(components(lcomponents))

      call graph_components(nvertex,xadj,lxadj,adjncy,ladjncy,components,lcomponents,ncomponents)
      write(*,*) 'ncomponents =', ncomponents
      write(*,*) 'vertex             component'
      do i = 1,nvertex
         write(*,*) i, components(i)
      end do
      if (all(components.eq.(/ 1, 1, 2, 1 /))) then
         write(*,*) 'Components seem O.K.'
      else   
         write(*,*) 'Components seem WRONG.'
      end if

      deallocate(components)
      deallocate(adjncy)
      deallocate(adjwgt)
      deallocate(xadj)

end program test_module_graph