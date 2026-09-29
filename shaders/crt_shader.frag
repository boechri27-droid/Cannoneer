uniform vec2 resolution;
uniform sampler2D texture; // The scene texture
uniform float bulgeStrength;  // Bulge strength (float)
uniform float saturation;     // Saturation (float)
uniform float contrast;       // Contrast (float)
uniform bool scanlines;       // Scanlines (boolean)

void main() {
    vec2 uv = gl_FragCoord.xy / resolution;

    // Calculate the distance from the center of the screen
    vec2 center = vec2(0.5, 0.5);
    vec2 offset = uv - center;
    float dist = length(offset);

    // Apply an outward bulging effect (reverse the direction)
    float maxDist = 0.7; // Beyond this distance, the effect will stop
    float distFactor = smoothstep(maxDist, 1.0, dist); // Gradually stop the effect near the edges
    float bulge = 1.0 + bulgeStrength * (dist * dist) * distFactor; // Apply a quadratic distortion based on distance

    // Apply the distortion to the UV coordinates (outward bulge)
    uv = center + offset * bulge; // Use multiplication instead of division for outward effect

    // Ensure UV coordinates are clamped to valid range [0, 1]
    uv = clamp(uv, vec2(0.0), vec2(1.0));

    // Sample the texture at the distorted UV
    vec3 color = texture2D(texture, uv).rgb;

    // Increase Saturation
    vec3 gray = vec3(dot(color, vec3(0.3, 0.59, 0.11))); // Calculate grayscale value
    color = mix(gray, color, saturation); // Mix original color with grayscale to increase saturation

    // Increase Contrast
    color = (color - 0.5) * contrast + 0.5; // Simple contrast adjustment

    // Apply scanlines for retro effect
    if (scanlines) {
        float scanline = mod(gl_FragCoord.y, 4.0) < 2.0 ? 0.6 : 1.0;
        color *= scanline;
    }

    // Output the final color
    gl_FragColor = vec4(color, 1.0);
}
