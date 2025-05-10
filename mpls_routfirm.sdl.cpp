s_ 

[3.5] | {
       fl_path
       $get_os_dtc.pkg {
          firm_path = /${adapt} 
          offset:(1024) 
          2_exp:(2048)
          offset3:(4096) 
       }
}

[3.5] | {
       read file *as current::active-dirChain ext_on:read 
       f3_payday /$adapt local-cgfg sys for.(local-frame/dirs)
}



