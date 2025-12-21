

single () {

   ./${1}_munit    --list
   cat ${1}.murun  | head --lines=1

   ./${1}_munit
   cat ${1}.murun  | tail --lines=2

}

printf "./master.sh unit-testing script ŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽ\n\n"
single "koios_verb"
single "koios_ditto"
single "koios_reuse"
single "koios_wave"
single "koios_read"
single "koios_parse"
single "koios_conv"
single "koios_code"
single "koios_prog"
single "koios_live"
printf "end-of-execution.  done, finito, completare ŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽŽ\n"

