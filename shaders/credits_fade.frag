uniform sampler2D texture;
uniform float fadeInStart;
uniform float fadeOutStart;

void main()
{
    vec4 color = texture2D(texture, gl_TexCoord[0].xy);
    float y = gl_FragCoord.y;

    float alpha = 1.0;

    // Fade in from bottom (starts at fadeInStart and fades over 100px upward)
    if (y > fadeInStart) {
        float fadeRange = 100.0;
        alpha = 1.0 - (y - fadeInStart) / fadeRange;
    }

    // Fade out at top (starts at fadeOutStart and fades over 100px downward)
    else if (y < fadeOutStart) {
        float fadeRange = 100.0;
        alpha = (y - (fadeOutStart - fadeRange)) / fadeRange;
    }

    // Clamp alpha and apply it without modifying RGB
    alpha = clamp(alpha, 0.0, 1.0);
    gl_FragColor = vec4(color.rgb, color.a * alpha);
}