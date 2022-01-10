## NO SLOTH

setwd("~/LIBGE/libge-examples-master/verilog/mul4_vector_tournament/Past Runs/runs_last_nosloth/")
files <- list.files(pattern="output*")
distances <- list.files(pattern="edit_distance*")
wd <- getwd() 

meanFit = 0
maxFit = 0
minFit =0
diversity =0
distance =0

for(i in 1:length(files)){
  
  ## MAX
  fname = as.name(paste(wd,"/",files[i], sep=""))
  
  data_frame <- read.delim(as.character(fname), header=FALSE)

  diversity <- rbind(diversity,t(data_frame$V6))
  
  meanFit <- rbind(meanFit,t(data_frame$V2))
  maxFit <- rbind(maxFit,t(data_frame$V3))
  minFit <- rbind(minFit,t(data_frame$V4))
  
  fname2 = as.name(paste(wd,"/",distances[i], sep=""))
  
  data_frame2 <- read.delim(as.character(fname2), header=FALSE)
  
  distance <- rbind(distance,t(data_frame2$V1))
  
}



maxFit <- maxFit[2:31,]
maxFit_plot1 <- apply(maxFit, 2, function(x) max(x))

meanFit <- meanFit[2:31,]
meanFit_plot <- colMeans(meanFit)

minFit <- minFit[2:31,]
minFit_plot <- apply(minFit, 2, function(x) min(x))

diversity <- diversity[2:31,]
diversity_plot <- colMeans(diversity)
mean_diversity <- mean(diversity_plot)

distance <- distance[2:31,]
distance_plot1 <- colMeans(distance)
mean_distance <- mean(distance)

plot(seq(1:length(distance_plot1)),distance_plot1, type = 'l', col = "blue", lwd = 2, main = "Mean Edit Distance No Sloth", xlab = "Generation", ylab = "Average Edit Distance", lty=1)
#plot(seq(1:length(diversity_plot)),diversity_plot, type = 'l', col = "blue", lwd = 2, main = "Mean Diversity No Sloth", xlab = "Generation", ylab = "Diversity", lty=1)
#points(seq(1:100),meanFit_plot, type = 'l', col = "red", lwd = 2, lty=2)
plot(seq(1:length(maxFit_plot1)),maxFit_plot1, type = 'l', col = "blue", lwd = 2, main = "Max and Mean Fitness No Sloth", xlab = "Generation", ylab = "Fitness", lty=1)
points(seq(1:length(meanFit_plot)),meanFit_plot, type = 'l', col = "red", lwd = 2, lty=2)

## SLOTH 25

setwd("~/LIBGE/libge-examples-master/verilog/mul4_vector_tournament/Past Runs/runs_last_25/")
files <- list.files(pattern="output*")
distances <- list.files(pattern="edit_distance*")
wd <- getwd() 

meanFit = 0
maxFit = 0
minFit =0
diversity =0
distance =0

for(i in 1:length(files)){
  
  ## MAX
  fname = as.name(paste(wd,"/",files[i], sep=""))
  
  data_frame <- read.delim(as.character(fname), header=FALSE)
  
  diversity <- rbind(diversity,t(data_frame$V6))
  
  meanFit <- rbind(meanFit,t(data_frame$V2))
  maxFit <- rbind(maxFit,t(data_frame$V3))
  minFit <- rbind(minFit,t(data_frame$V4))
  
  fname2 = as.name(paste(wd,"/",distances[i], sep=""))
  
  data_frame2 <- read.delim(as.character(fname2), header=FALSE)
  
  distance <- rbind(distance,t(data_frame2$V1))
  
}



maxFit <- maxFit[2:31,]
maxFit_plot1 <- apply(maxFit, 2, function(x) max(x))

meanFit <- meanFit[2:31,]
meanFit_plot <- colMeans(meanFit)

minFit <- minFit[2:31,]
minFit_plot <- apply(minFit, 2, function(x) min(x))

diversity <- diversity[2:31,]
diversity_plot <- colMeans(diversity)
mean_diversity <- mean(diversity_plot)

distance <- distance[2:31,]
distance_plot2 <- colMeans(distance)
mean_distance <- mean(distance)

plot(seq(1:length(distance_plot2)),distance_plot2, type = 'l', col = "blue", lwd = 2, main = "Mean Edit Distance Sloth 25", xlab = "Generation", ylab = "Average Edit Distance", lty=1)
#plot(seq(1:length(diversity_plot)),diversity_plot, type = 'l', col = "blue", lwd = 2, main = "Mean Diversity No Sloth", xlab = "Generation", ylab = "Diversity", lty=1)
#points(seq(1:100),meanFit_plot, type = 'l', col = "red", lwd = 2, lty=2)
plot(seq(1:length(maxFit_plot1)),maxFit_plot1, type = 'l', col = "blue", lwd = 2, main = "Max and Mean Fitness Sloth 25", xlab = "Generation", ylab = "Fitness", lty=1)
points(seq(1:length(meanFit_plot)),meanFit_plot, type = 'l', col = "red", lwd = 2, lty=2)

# Distances
plot(seq(1:length(distance_plot1)),distance_plot1, type = 'l', col = "blue", lwd = 2, main = "Mean (30 runs) Edit Distance No Sloth (Blue) vs Sloth 25 (Red)", xlab = "Generation", ylab = "Average Edit Distance", lty=1)
points(seq(1:length(distance_plot2)),distance_plot2, type = 'l', col = "red", lwd = 2, lty=2)