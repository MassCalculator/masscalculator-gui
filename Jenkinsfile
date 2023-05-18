pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Environment setup') {
            steps {
                sh "sudo tools/installers/essentials.sh"
            }
        }
        stage('Build') {
            parallel {
                stage('Debug') {
                    steps {
                        sh "cmake -B build/masscalculator-gui-Debug -G Ninja -DCMAKE_BUILD_TYPE=Debug"
                        sh "cmake --build build/masscalculator-gui-Debug --config Debug"
                    }
                }
                stage('Release') {
                    steps {
                        sh "cmake -B build/masscalculator-gui-Release -G Ninja -DCMAKE_BUILD_TYPE=Release"
                        sh "cmake --build build/masscalculator-gui-Release --config Release"
                    }
                }
            }
        }
        stage('Test') {
            parallel {
                stage('Debug') {
            steps {
                // @todo(jimmyhalimi): Update stages that are in progress.
                echo 'Test stage (Debug) is in progress'
            }
                }
                stage('Release') {
            steps {
                // @todo(jimmyhalimi): Update stages that are in progress.
                echo 'Test stage (Release) is in progress'
            }
                }
            }
        }
        stage('Package') {
            steps {
                // @todo(jimmyhalimi): Update stages that are in progress.
                echo 'Package stage is in progress'
            }
        }
        stage('Deploy') {
            steps {
                // @todo(jimmyhalimi): Update stages that are in progress.
                echo 'Deploy stage is in progress'
            }
        }
    }
}
