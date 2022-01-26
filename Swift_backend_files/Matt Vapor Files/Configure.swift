import Fluent
import FluentPostgresDriver
import Vapor
//import FluentPostGIS

// configures your application
public func configure(_ app: Application) throws {
    if app.environment == .development {
        app.logger.logLevel = .debug
    }
    
    
    
    // uncomment to serve files from /Public folder
    app.middleware.use(FileMiddleware(publicDirectory:app.directory.publicDirectory))
    app.middleware.use(CORSMiddleware())
    
   
    if let postgresUrl = Environment.get("DATABASE_URL") {
        var postgresConfig = PostgresConfiguration(url: postgresUrl)!
        postgresConfig.tlsConfiguration = TLSConfiguration.forClient(certificateVerification: .none)
        app.databases.use(.postgres(configuration: postgresConfig), as: .psql)
    } else {
        app.databases.use(.postgres(
            hostname: Environment.get("DATABASE_HOST") ?? "localhost",
            port: Environment.get("DATABASE_PORT").flatMap(Int.init(_:)) ?? PostgresConfiguration.ianaPortNumber,
            username: Environment.get("DATABASE_USERNAME") ?? "mattbass",
            password: Environment.get("DATABASE_PASSWORD") ?? "password",
            database: Environment.get("DATABASE_NAME") ?? "matt-vapor"
        ), as: .psql)
    }
    
   

    //app.migrations.add(EnablePostGISMigration())
    
    app.migrations.add(CreateTodo())
    
    // register routes
    try routes(app)
    
    
    try app.autoMigrate().wait()
    
    
}


