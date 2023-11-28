
#!/bin/bash

menu_choice=""
current_cd=""
title_file="title.cdb"
tracks_file="tracks.cdb"
temp_file="/tmp/cdb.$$"
trap 'rm -rf /tmp/cdb.$$' EXIT

# 确认函数
get_confirm() {
	echo -e "are you sure? \c"
	while true
	do
		read x
		case "${x}" in
			[yY] | [yY][eE][Ss] )
				return 0
				;;
			[nN] | [nN][oO] )
				echo "cancelled"
				return 1
				;;
			* )
				echo "please enter yes/no"
				;;
		esac
	done
}

# 输入数据到文件
insert_title() {
	echo $* >> ${title_file}
	return
}

insert_track() {
	echo $* >> ${tracks_file}
	return
}

add_record_tracks() {
	echo "enter track info for this CD"
	echo "when no more tracks enter q"

	cdtrack=1
	cdtitle=""

	while [ "${cdtitle}" != "q" ]
	do
		echo -e "track ${cdtrack} track title? \c"
		read tmp
		
		cdtitle=${tmp%%,*}
		if [ "${tmp}" != "${cdtitle}" ]		#校验是否包含,
		then
			echo "sorry: no commas allowed"
			continue
		fi

		if [ -n "${cdtitle}" ]
		then
			if [ "${cdtitle}" != "q" ]
			then
				insert_track ${cdcatnum} ${cdtrack} ${cdtitle}
			fi
		else
			cdtrack=$((cdtrack-1))	# 应对外层的++
		fi

		cdtrack=$((cdtrack+1))
	done
}

add_records() {
	echo -e "enter a catalog name \c"
	read tmp
	cdcatnum=${tmp%%,*}

	echo -e "enter title \c"
	read tmp
	cdtitle=${tmp%%,*}

	echo -e "enter type \c"
	read tmp
	cdtype=${tmp%%,*}

	echo -e "enter artist/composer \c"
	read tmp
	cdac=${tmp%%,*}

	echo "about add new entry"
	echo "${cdcatnum} ${cdtitle} ${cdtype} ${cdac}"
	
	if get_confirm
	then
		insert_title ${cdcatnum} ${cdtitle} ${cdtype} ${cdac}
		add_record_tracks
	else
		remove_records
	fi
	
	return
}