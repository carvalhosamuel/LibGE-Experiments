## app.R ##
## LibGE Live Stats - By Samuel Carvalho - Oct 2020 ##


library(shiny)
library(shinydashboard)
library(dygraphs)
library(htmlwidgets)

js <- HTML(
  'function Export(id) {',
  '  const a = document.createElement("a");',
  '  document.body.append(a);',
  '  a.download = "dygraph.png";',
  '  a.href = $(id).attr("src");',
  '  a.click();',
  '  a.remove();',
  '}'
)

ui <- dashboardPage(
  
  
  #Title that comes on the browser tab
  title = "LibGE Live Stats",
  
  dashboardHeader(title = "LibGE Live Stats"),
  dashboardSidebar(
    sidebarMenu(
      menuItem("Fitness", tabName = "fitness", icon = icon("dashboard")),
      menuItem("Diversity", tabName = "diversity", icon = icon("dashboard")),
      menuItem("Statistics", tabName = "Statistics", icon = icon("dashboard"))
    )
  ),
  dashboardBody(
   
    tabItems( 
    
        tabItem(tabName = "fitness",
        fluidRow(
          box(
            title = "All Fitness Scores",
            width=12,
            collapsible = TRUE,
            tags$head(tags$script(js)),
            #tags$img(id = "img", style = "display: none;"),
            tags$img(id = "img", style = "display: none;width:1000px;height:600px;"),
            br(),
            actionButton("export", "Export to PNG", onclick = "Export(img);"),
            br(),
            dygraphOutput("AllFit"),
            tags$script(src = "dygraph-extra.js")
          ),
          box(
            title = "Individual Graphs",
            collapsible = TRUE,
            collapsed = TRUE,
            width = 12,
            dygraphOutput("MaxFit"),
            dygraphOutput("MeanFit2"),
            dygraphOutput("MinFit")
          ),
          box(
            h3("Quick Insights:"),
            width = 12,
            # Dynamic infoBoxes
            infoBoxOutput("generation"),
            infoBoxOutput("bestfitness"),
            infoBoxOutput("best_ever"),
            )
        )
      ),
      
      tabItem(tabName = "diversity",
              fluidRow(
                
                box(
                    width = 12,
                    tags$head(tags$script(js)),
                    tags$img(id = "galibdiv", style = "display: none;"),
                    br(),
                    actionButton("export", "Export to PNG", onclick = "Export(galibdiv);"),
                    br(),
                    dygraphOutput("GAlibDiversity"),
                    tags$script(src = "dygraph-extra.js"),
                    h3("Quick Insights:"),
                    # Dynamic infoBoxes
                    infoBoxOutput("maxdiversity", width = 3),
                    infoBoxOutput("currentdiversity", width = 3)
                )
              ),
              fluidRow(
                box(
                    width = 12,
                    dygraphOutput("SemanticDiversity"),
                    h3("Quick Insights:"),
                    # Dynamic infoBoxes
                    infoBoxOutput("maxSdiversity", width = 3),
                    infoBoxOutput("currentSdiversity", width = 3)
                )
              ),
              fluidRow(
                box(
                  width = 12,
                  dygraphOutput("EditDistanceDiversity"),
                  h3("Quick Insights:"),
                  # Dynamic infoBoxes
                  infoBoxOutput("maxEdiversity", width = 3),
                  infoBoxOutput("currentEdiversity", width = 3)
                )
              )
             
      ),
      
      tabItem(tabName = "Statistics",
              fluidRow( 
                
                box(
                  width=12,
                  verbatimTextOutput("stats_file"),
                )
              )
      )
    
    )
    
  )
)

fileData <- reactiveFileReader(10, NULL, 'log/output_data.log', read.csv, header = FALSE, sep='\t')
statsfile <- reactiveFileReader(10, NULL, 'log/output_data.log', read.csv, header = TRUE, sep='\t')
diversityFile<- reactiveFileReader(10, NULL, 'log/edit_distance', read.csv, header = FALSE, sep='\t')

server <- function(input, output) {
  
  output$AllFit <- renderDygraph({
    
    data <- fileData()
    plot_df <- as.data.frame(cbind(data$V1,data$V2,data$V3,data$V4))
    names(plot_df) <- c("Gen","Mean","Max","Min")
    
    #Implementation of the graphical interface and options
    graph <<- dygraph(plot_df, main = "Fitness Scores", ylab = "Score") %>%
      dyOptions(drawGrid = TRUE) %>%
      dyRangeSelector() %>%
      onRender(c(
        "function(el,x) {",
        "  Dygraph.Export.asPNG(", # more options: https://cavorite.com/labs/js/dygraphs-export/
        "    this.dygraph, document.getElementById('img'), {backgroundColor: 'white'}",
        "  );",
        "}"
      ))
    
    #Returns graph object to UI
    graph
    
    
  })
  
  
  
  
  
  #Renders infobox 
  output$generation <- renderInfoBox({
    
    data <- fileData()
    gen <- max(data$V1)
    infoBox("Current Generation", gen, icon = icon("history"),color = "blue", fill = TRUE, width = 2)
    
  })
  
  #Renders infobox 
  output$bestfitness <- renderInfoBox({
    
    data <- fileData()
    best <- max(data$V3)
    infoBox("Best Score of this Run", best, icon = icon("trophy"),color = "green", fill = TRUE, width = 2)
    
  })
  
  #Global Best ever
  bestever <<- 0
  
  #Renders infobox 
  output$best_ever <- renderInfoBox({
    
    data <- fileData()
    best <- max(data$V3)
    
    if(best > bestever){
      bestever <<- best
    }
    
    infoBox("Best Score of All Runs", bestever, icon = icon("trophy"),color = "green", fill = TRUE, width = 2)
    
  })
  
  output$MeanFit2 <- renderDygraph({
    
    data <- fileData()
    plot_df <- as.data.frame(cbind(data$V1,data$V2))
    
    
    #Implementation of the graphical interface and options
    graph <<- dygraph(plot_df, main = "Mean Fitness", ylab = "Score") %>%
      dyOptions(drawGrid = TRUE) %>%
      dyRangeSelector()  
    
    #Returns graph object to UI
    graph
    
    
  })
  
  output$MaxFit <- renderDygraph({
    
    data <- fileData()
    plot_df <- as.data.frame(cbind(data$V1,data$V3))
    
    
    #Implementation of the graphical interface and options
    graph <<- dygraph(plot_df, main = "Max Fitness", ylab = "Score") %>%
      dyOptions(drawGrid = TRUE) %>%
      dyRangeSelector()  
    
    #Returns graph object to UI
    graph
    
    
  })
  
  output$MinFit <- renderDygraph({
    
    data <- fileData()
    plot_df <- as.data.frame(cbind(data$V1,data$V4))
    
    
    #Implementation of the graphical interface and options
    graph <<- dygraph(plot_df, main = "Min Fitness", ylab = "Score") %>%
      dyOptions(drawGrid = TRUE) %>%
      dyRangeSelector()  
    
    #Returns graph object to UI
    graph
    
    
  })
  
  output$GAlibDiversity <- renderDygraph({
    
    data <- fileData()
    plot_df <- as.data.frame(cbind(data$V1,data$V6))
    
    
    #Implementation of the graphical interface and options
    graph <<- dygraph(plot_df, main = "GALib Diversity", ylab = "Average GALib Diversity") %>%
      dyOptions(drawGrid = TRUE) %>%
      dyRangeSelector() %>%
      onRender(c(
        "function(el,x) {",
        "  Dygraph.Export.asPNG(", # more options: https://cavorite.com/labs/js/dygraphs-export/
        "    this.dygraph, document.getElementById('galibdiv'), {backgroundColor: 'white'}",
        "  );",
        "}"
      ))  
    
    #Returns graph object to UI
    graph
    
    
  })
  
  #Renders infobox 
  output$maxdiversity <- renderInfoBox({
    
    data <- fileData()
    best <- max(data$V6)
    infoBox("Highest Diversity", best, icon = icon("arrow-up"),color = "green", fill = TRUE, width = 2)
    
  })
  
  
  #Renders infobox 
  output$currentdiversity <- renderInfoBox({
    
    data <- fileData()
    current <- data$V6[length(data$V6)]
    infoBox("Current Diversity", current, icon = icon("arrow-right"),color = "green", fill = TRUE, width = 2)
    
  })
  
  output$SemanticDiversity <- renderDygraph({
    
    data <- fileData()
    plot_df <- as.data.frame(cbind(data$V1,data$V5^2))
    
    #Implementation of the graphical interface and options
    graph <<- dygraph(plot_df, main = "Semantic Diversity", ylab = "Variance of Scores") %>%
      dyOptions(drawGrid = TRUE) %>%
      dyRangeSelector()  
    
    #Returns graph object to UI
    graph
    
    
  })
  
  #Renders infobox 
  output$maxSdiversity <- renderInfoBox({
    
    data <- fileData()
    best <- max(data$V5)^2
    infoBox("Highest Diversity", best, icon = icon("arrow-up"),color = "green", fill = TRUE, width = 2)
    
  })
  
  
  #Renders infobox 
  output$currentSdiversity <- renderInfoBox({
    
    data <- fileData()
    current <- data$V5[length(data$V5)]
    infoBox("Current Diversity", current, icon = icon("arrow-right"),color = "green", fill = TRUE, width = 2)
    
  })
  
  
  
  output$EditDistanceDiversity <- renderDygraph({
    
     
    distance <- diversityFile()
 
    plot_df <- as.data.frame(cbind(seq(1:dim(distance)[1]),distance))  
  
    #Implementation of the graphical interface and options
    graph <<- dygraph(plot_df, main = "Phenotype Edit Distance Diversity", ylab = "Average Edit Distance") %>%
      dyOptions(drawGrid = TRUE) %>%
      dyRangeSelector()  
    
    #Returns graph object to UI
    graph
    
    
  })
  
  #Renders infobox 
  output$maxEdiversity <- renderInfoBox({
    
    data <- diversityFile()
    best <- max(data)
    infoBox("Highest Diversity", best, icon = icon("arrow-up"),color = "green", fill = TRUE, width = 2)
    
  })
  
  
  #Renders infobox 
  output$currentEdiversity <- renderInfoBox({
    
    distance <- diversityFile()
    index <- dim(distance)[1]  
    current <- distance[index,]
    infoBox("Current Diversity", current, icon = icon("arrow-right"),color = "green", fill = TRUE, width = 2)
    
  })
  
  
  
  

  
  #Renders stats file
  output$stats_file <- renderPrint({
    
    options(max.print=1000000)
    stats <- statsfile()
    names(stats) <- c("Generation","Mean","Max","Min","SD","Diversity")
    stats
    
  })
  
}

shinyApp(ui, server)