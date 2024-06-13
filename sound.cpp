#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>

const float PI = 3.14159265358979323846f;

// Genera un pitido sinusoidal
void generateSineWave(float frequency, float duration, int sampleRate, std::vector<short>& samples) {
    int numSamples = static_cast<int>(duration * sampleRate);
    samples.resize(numSamples);
    
    for (int i = 0; i < numSamples; ++i) {
        float t = static_cast<float>(i) / sampleRate;
        float amplitude = 0.5f * (1 - cos(2 * PI * i / numSamples)); // Suavizado con función coseno
        samples[i] = static_cast<short>(32767 * amplitude * sin(2 * PI * frequency * t));
    }
}

int main( int argc, char* argv[] ) {
    // Inicializa OpenAL
    ALCdevice* device = alcOpenDevice(nullptr);
    if (!device) {
        std::cerr << "Failed to open default OpenAL device." << std::endl;
        return -1;
    }

    ALCcontext* context = alcCreateContext(device, nullptr);
    if (!alcMakeContextCurrent(context)) {
        std::cerr << "Failed to make context current." << std::endl;
        return -1;
    }

    if (argc < 4) return 1;

    // Parámetros del pitido
    float frequency = std::stod(argv[1]); // Frecuencia del pitido en Hz (ejemplo: A4)
    float duration = std::stod(argv[2]);    // Duración del pitido en segundos
    int sampleRate = std::stoi(argv[3]);   // Frecuencia de muestreo

    // Genera los datos del pitido
    std::vector<short> samples;
    generateSineWave(frequency, duration, sampleRate, samples);

    // Crea un búfer y carga los datos del pitido en él
    ALuint bufferId;
    alGenBuffers(1, &bufferId);
    alBufferData(bufferId, AL_FORMAT_MONO16, samples.data(), samples.size() * sizeof(short), sampleRate);

    // Crea una fuente y adjunta el búfer a ella
    ALuint sourceId;
    alGenSources(1, &sourceId);
    alSourcei(sourceId, AL_BUFFER, bufferId);

    // Reproduce el pitido
    alSourcePlay(sourceId);

    // Espera a que el pitido termine
    ALint state;
    do {
        alGetSourcei(sourceId, AL_SOURCE_STATE, &state);
    } while (state == AL_PLAYING);

    // Limpieza
    alDeleteSources(1, &sourceId);
    alDeleteBuffers(1, &bufferId);
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context);
    alcCloseDevice(device);

    return 0;
}
