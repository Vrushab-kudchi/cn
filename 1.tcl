
Program 1: Simulate a three nodes point — to — point network with duplex links between them. Set the queue size and vary the bandwidth and find the number of packets dropped.

set ns [new Simulator]
set namfile [open nsl1.nam w]
$ns namtrace-all $namfile
set tracefile [open nsl1.tr w]
$ns trace-all $tracefile

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 0.5Mb 10ms DropTail

$ns queue-limit $n0 $n1 05
$ns queue-limit $n1 $n2 05

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp


set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink

#connect tcp src and sink
$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set packetSize_ 1024

$sink set class_ 1
$ns color 1 Blue

$tcp set class_ 2
$ns color 2 Red


proc finish {} {

	global ns namfile tracefile
	$ns flush-trace
	close $namfile
	close $tracefile
		set awkCode {
		BEGIN {}
    		{
			if($1 == "d" && $4 ==2)
			{
				dcount = dcount + $6
				print $2,dcount>>"nsl1.data"
			}
		}
		END {}
	}
	exec awk $awkCode nsl1.tr
	exec xgraph -bb -tk -x Time -y Bytes nsl1.data -bg white &
	exec nam nsl1.nam &
	exit 0

}
$ns at 0.0 "$ftp start"
$ns at 9.0 "$ftp stop"
$ns at 10.0 "finish"

$ns run
