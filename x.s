


  
	 


 
	 
	
.data
	fn_noclass_main_a:  .word 0
	fn_noclass_does_b:  .word 0
.text
noclass_does:
	lw	$a0, fn_noclass_does_b
	li	$v0, 5
	syscall
noclass_main:
	li	$t0, 3
	sw	$t0, fn_noclass_does_b

	j	noclass_does


