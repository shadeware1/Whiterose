s_ 

[3.5] | {
       $get_sip.pkg
       $get_unread_obfuscate.pkg {
             fpn init_sip_con = createNew(prc/local-frame) sip_controller; connect 
             init_sip con(ext)
             prc_sip address ("hd-obs(unreadable)") 
             sip_port 5060; sip_usr:sip_pass --use temp-db(local-frame/logins)
             auth_digest  init_sip 
    }
}

[3.5] | {
       fpn_auth sip 
}

[3.5] | {
       prc_ sip.auth create(auth-chain)
       para(creds) *if = current::chain(creds/local-frame(^1@.mn-logins)) = trigger(@get_temp-cacheLog) reload-redir = true start.sys
}

[3.5] | {
       class:open_block "traffic_sip" ctrl_sip listen 
       mon.port ext_para(mon) 
       loop: 
       prc key = mon_recv *if dta sig = tk_sig /(frame-change)/ ext_exp 
}

[3.5] | {
       int sip_opt 
       int para(sip.adr::sip.port) int ext
       response(int) stop
       response_dta = fill(exp) dta create<tk>(repo) stat:current_flow 
       use.exp trigger:main 
}

