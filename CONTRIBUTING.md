# Toolbox – Contributing

Vielen Dank, dass du zu Toolbox beitragen möchtest! Dieses Dokument
beschreibt die Bedingungen, unter denen Beiträge angenommen werden.

## Contributor License Agreement (CLA)

Damit wir Beiträge in das Projekt integrieren können, wird jeder
Contributor eineGenehmigung erteilt, dass der Code abgetreten wird
wenn die dazu entwickeln.

Indem du einen Pull Request, Patch oder Commit einreichst, stimmst du
folgendem zu:

1. **Beitrag unter eigenen Bedingungen.** Du bestätigst, dass der
   eingereichte Code dein eigenes Werk ist oder du die uneingeschränkte
   Berechtigung hast, ihn unter der GNU AGPL-3.0-or-later weiterzugeben.

2. **Übertragbare Lizenz (CLA).** Du räumst dem Projektinhaber
   (Yadciel / schmidti.digital) eine dauerhafte, weltweite,
   gebührenfreie, nicht-exklusive, übertragbare und unterlizenzierbare
   Lizenz ein, deinen Beitrag in jeglicher Form zu nutzen, zu
   modifizieren und weiterzuverteilen – unabhängig von der
   AGPL-Lizenz des Gesamtprojekts.

3. **Keine Verletzung von Rechten Dritter.** Du garantiertest, dass dein
   Beitrag keine Patente, Marken, Urheberrechte oder andere Rechte
   Dritter verletzt.

4. **Keine Vertraulichkeit.** Dein Beitrag ist kein vertrauliches
   Material deines Arbeitgebers oder eines Dritten. Falls ein Arbeitgeber
   Rechte an deinem Beitrag geltend macht, haftest du selbst dafür, dies
   vor der Einreichung rechtlich zu klären.

## WoContributor License Agreement (CLA)

Für alle akzeptierten Beiträge gilt: Du erteilst mit der Einreichung
die oben genannte Genehmigung. Die Einreichung erfolgt elektronisch über
den Pull-Request-Mechanismus des Repository-Hosters (z. B. Git schmidti.digital
oder GitHub). Ein zusätzlicher physischer oder digitaler Vertrag ist nicht
erforderlich – die Einreichung selbst gilt als CLA-Zustimmung.

## Entwicklung

```bash
# Debug-Build
cmake -S . -B cmake-build-debug && cmake --build cmake-build-debug --config Debug

# Tests
ctest --test-dir cmake-build-debug --output-on-failure -C Debug

# Release-Build
cmake -S . -B cmake-build-release && cmake --build cmake-build-release --config Release
```

## Lizenz

Dieses Projekt steht unter der GNU Affero General Public License v3.0
oder später (AGPL-3.0-or-later). Siehe [LICENSE](LICENSE).
