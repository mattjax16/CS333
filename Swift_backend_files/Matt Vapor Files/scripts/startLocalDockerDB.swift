#!/usr/bin/swift
import Foundation

let databaseName = "matt-vapor"
let username = "mattbass"
let password = "password"
let port = 5432
let containerName = "postgres-matt-vapor"

print("Starting local database in container \(containerName). \nDatabase name is \(databaseName), username is \(username) and password is \(password)")

@discardableResult
func shell(_ args: String...) -> Int32 {
    let task = Process()
    task.launchPath = "/usr/bin/env"
    task.arguments = args
    task.launch()
    task.waitUntilExit()
    return task.terminationStatus
}

let dockerResult = shell("docker", "run", "--platform", "linux/amd64", "--name", containerName, "-e",  "POSTGRES_DB=\(databaseName)", "-e", "POSTGRES_USER=\(username)" , "-e", "POSTGRES_PASSWORD=\(password)", "-p", "\(port):5432", "-d", "mdillon/postgis")

guard dockerResult == 0 else {
    print("❌ ERROR: Failed to create the database")
    exit(1)
}

print("Database created in Docker 🐳")
