#!/usr/bin/awk -f

# Set the start time and end time of the throughput calculation
# Adjust these values based on your simulation scenario
START_TIME = 10.0
END_TIME = 150.0

# Set the node IDs of the source and destination for throughput calculation
SOURCE_NODE = 0
DESTINATION_NODE = 1

# Set the packet size used in the simulation
PACKET_SIZE = 1000

# Initialize variables
totalBytes = 0
startTime = 0
endTime = 0

# Process each line in the trace file
{
    # Check if it's a packet transmission event
    if ($1 == "r" && $3 == "AGT" && $4 == "tcp") {
        currentTime = $2
        
        # Check if the current time is within the desired range
        if (currentTime >= START_TIME && currentTime <= END_TIME) {
            nodeID = $8
            packetSize = $NF
            
            # Check if it's the desired source and destination nodes
            if (nodeID == SOURCE_NODE || nodeID == DESTINATION_NODE) {
                # Calculate the throughput
                if (startTime == 0) {
                    startTime = currentTime
                }
                
                endTime = currentTime
                totalBytes += packetSize
            }
        }
    }
}

# Calculate the throughput in Mbps
duration = endTime - startTime
throughput = (totalBytes * 8) / (duration * 1000000)

# Print the throughput result
print "Throughput", throughput, "Mbps\n"
printf("Throughput: %.2f Mbps\n", throughput)
