s_ 

[3.5] | {
       db_path:list = /lister/(loca-frame/${adapt}) 
       wip.cmd = "-c; rmrf/(lister)" 
       read *as db_path(chain)
}

[3.5] | {
       $get_burner.pkg {
          burn.reg(all) 
          burn.disk(all) -(of_current:dirChain) 
       }
}

